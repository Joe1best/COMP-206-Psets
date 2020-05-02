#!/bin/bash


#The file responsible for displaying messages when terminal is opened
#is the .bash_profile. To find where this file is, we use the pwd command
#on ~/.bash_profile
loging_file=".bash_profile"
path=`pwd ~/.bash_profile`
abPath=`pwd`

#Command to find the hostname in the shh
#host=`hostname`

#This command below clears the bash_profile and clears it e
> $path/$loging_file

#Writes the echo command in the .bashprofile by redirecting the message to 
#the bash_profile file
echo -e "host=\`hostname\`\necho "Welcome to \$host!"" >> $path/$loging_file
#echo echo "Welcome to \$host!" >> $path/$loging_file


#The command below extract how many times a user is signed into the ssh. This is 
#done by combining the command 'who' which displays the people of signed into ssh.
#grep filters out only the $USER, and wc returns how many times grep found matches. 
#-l is to display the number of lines. 
num=`who | grep $USER | wc -l`

echo echo "You have $num login sessions to this host." >> $path/$loging_file

echo echo \`fortune\` >> $path/$loging_file

#Adds the new alias command to the bash_profile. 
echo alias comp206=\'cd $abPath/Projects/COMP206\' >> $path/$loging_file

#Displays the following message in a special font. This is for the 
#do whatever you what question
msg="Happy Hacking"
echo echo $msg \| figlet >> $path/$loging_file

#This export command changes the PS1 string to what we want displayed
echo export PS1=\"$USER@\$host[$(date +%H:%M:%S)]:\\w\\$ \" >> $path/$loging_file
