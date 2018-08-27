#! /bin/bash


echo "This script will add license preambule to files selected by dirs and filters arguments"


# directories who contented the files that need to add copyright
dirs=(/home/cfse/Stage_Malo/CPACSCreatorTotal/CreatorLib/CPACSCreatorLib /users/disk9/cfse/Stage_Malo/CPACSCreatorTotal/CreatorLib/CPACSCreatorLibTests/CreatorTests/)
# extention to take in account
filters=( .cpp .h )
# the files that will be modified
files=()


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


# get the files using filters and dirs with find cmd
for d in ${dirs[*]}
do
    echo "$d"
    for fi in ${filters[*]}
    do
        echo $fi
        while IFS=  read -r -d $'\0'
        do
            files+=("$REPLY")
        done < <(find "$d" -name "*$fi" -print0)
    done
done


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

 



