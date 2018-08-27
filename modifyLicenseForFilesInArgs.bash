#! /bin/bash


echo "This script will add license preambule to the files passed as arguments"


# the array that hold the files 
files=()

for file in "$@"
do
    if [ -a "$file" ]
    then
        files+=("$file")
    else 
        echo "file $file not found"
    fi
done


copyright='/*
* Copyright (C) 2018 CFS Engineering
*
* Created: 2018 Malo Drougard <malo.drougard@protonmail.com>
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
*/'



# escapestr_sed()
# escape characters in argument 1 that could be interpreted as
# special characters by sed
escape_sed() {
     echo "$1" | sed -e 's/[]\/$*.^[]/\\&/g'
}

echo "The folowing files will be edited:"
for f in ${files[*]}
do
   echo "$f"
done

read -p "Continue? " -n 1 -r
echo 
if [[ $REPLY =~ ^[Yy]$  ]]
then

    for f in ${files[*]} 
    do
        lineCount=1
        while IFS= read -r line
        do
            lineSed=$(escape_sed "$line")
            sed -i "${lineCount}i $lineSed" $f
            let "lineCount = $lineCount + 1"
        done < <(printf '%s\n' "$copyright")
    done
  
fi

 



