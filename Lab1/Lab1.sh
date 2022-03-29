# Name: Yihui(Andy) Qin
# Date: Jan 04 2022 
# Title: Lab1 – task 1 
# Description: This program writes the full name of home directory, user name,
# The value of PATH environmental variable,the current directory path, the
# process ID, and the number of users logged in.
# The program also checks if  the user goes by certain name; if so, the program # will continue and ask the user to create a custom triangle.
# The area of the triangle will be returned and a promopt to restart will appear  
# Sample SHell Program for Lab Assignment
# !/bin/sh
echo Executing $0
echo $(/bin/ls | wc -l) files
wc -l $(/bin/ls)
echo "HOME="$HOME
echo "USER="$USER
echo "PATH="$PATH
echo "PWD="$PWD
echo "\$\$"=$$
user=`whoami`
numusers=`who | wc -l`
echo "Hi $user! There are $numusers users logged on."
# Not sure if this is the right way to approach, but I simply changed the
# username qualification to be my username
if [ $user = "yqin2" ]
then
        echo "Now you can proceed!"
else
        echo "Check who logged in!" 
        exit 1
fi

response="Yes"
while [ $response != "No" ]
do
        echo "Enter height of rectangle: "
        read height
        echo "Enter width of rectangle: "
        read width
        area=`expr $height \* $width`
        echo "The area of the rectangle is $area"

        echo "Would you like to repeat for another rectangle [Yes/No]?"
        read response
done

response="Yes"
while [ $response != "No" ]
do
        echo "Enter radius of circle: "
        read radius
        echo "The area of the circle is:"
        #use math funtion a() (arctan) to compute PI and use it in the area of 
        #circle
        echo "scale = 5; $radius * $radius * 4*a(1)" | bc -l
        echo "Would you like to repeat for another circle [Yes/No]?"
        read response

done
