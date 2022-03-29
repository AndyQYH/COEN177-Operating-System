gcc -o Step4 step4.c
for file in file1.txt file2.txt file3.txt file4.txt 
do 
    		for buffer in 100 1000 10000 100000
    		do
        		echo "Step4 $file $buffer test.txt"
        		time ./Step4 $file $buffer test.txt
        		echo " "
    		done
done
rm Step4 