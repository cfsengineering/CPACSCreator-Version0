/*
* Copyright (C) 2007-2013 German Aerospace Center (DLR/SC)
*
* Created: 2012-08-27 Martin Siggel <Martin.Siggel@dlr.de>
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/
/*
 * @brief Create a basic_streambuf that emit a Qt signal when some sequence is puted.
 *
 * The buffer will override the buffer of the stream given as input and take its place.
 * If the duplicate bool is set to true, the message is forward to the old buffer.
 */

#ifndef QDEBUGSTREAM_H
#define QDEBUGSTREAM_H

#include "tigl_internal.h"
#include <QObject>
#include <QMutex>
#include <iostream>

///////////////////////////////////////////////////////////////////////////
//
class QDebugStream : public QObject, std::basic_streambuf<char>
{

   Q_OBJECT

signals:
   void sendString(QString text);

public:

    QDebugStream(std::ostream &stream, bool duplicate = false) : m_stream(stream)
    {
      this->duplicate = duplicate;
      m_old_buf = stream.rdbuf(); // save the old buffer
      stream.rdbuf(this);   // associate the argument stream (eg: std::cout) with this buffer


    }
    ~QDebugStream() OVERRIDE
    {
        // output anything that is left
        if (!m_string.empty()) {
            emit sendString(m_string.c_str());
        }
        m_stream.rdbuf(m_old_buf);
    }
 
    void setMarkup(const QString& front, const QString& back)
    {
         this->front = front; this->back = back;
    }

protected:
    int_type overflow(int_type v) OVERRIDE
    {
        mutex.lock();


        // sending to the old buffer
        if(duplicate) m_old_buf->sputc(v);


        // emit a signal
        if (v == '\n') {
            emit sendString(front + m_string.c_str() + back);
            m_string.erase(m_string.begin(), m_string.end());
        }
        else {
            m_string += v;
        }
      
        mutex.unlock();
        return v;
    }

    std::streamsize xsputn(const char *p, std::streamsize n) OVERRIDE 
    {
        mutex.lock();

        // sending to the old buffer
        if(duplicate) m_old_buf->sputn(p, n);


        // emit a signal
        m_string.append(p, p + n);
        size_t pos = 0;
        while (pos != std::string::npos) {
            pos = m_string.find('\n');
            if (pos != std::string::npos) {
                std::string tmp(m_string.begin(), m_string.begin() + pos);
                emit sendString(front + tmp.c_str() + back);
                //log_window->appendPlainText(tmp.c_str());
                m_string.erase(m_string.begin(), m_string.begin() + pos + 1);
            }
        }

        mutex.unlock();
        return n;
    }

private:
    std::ostream &m_stream;
    std::streambuf *m_old_buf;
    std::string m_string;
    QMutex mutex;
    QString front, back;
    bool duplicate;
};


#endif // QDEBUGSTREAM_H
