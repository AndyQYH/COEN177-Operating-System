gcc -o Step3 step3.c
for file in file1.txt file2.txt file3.txt file4.txt 
do 
    		for buffer in 100 1000 10000 100000
    		do
        		echo "Step3 $file $buffer"
        		time ./Step3 $file $buffer
        		echo " "
    		done
done
rm Step3