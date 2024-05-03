#1 Basic operations
echo "Enter two numbers:"
read a
read b
echo "Addition is : $(echo "$a+$b"|bc)"
echo "Subtraction is : `expr $a - $b`"
echo "Multiplication is : `expr $a \* $b`"
echo "Division is : `expr $a / $b`"

#val= `expr $a+$b`
#val= $(expr $a+ $b)
#Val= $(echo "$a+$b"|bc) bc: basic calculator

#2 Area and perimeter of circle 
echo "Enter Radius of circle:"
read r
echo "Area is $(echo "3.14 * $r * $r" | bc) sq. units"
echo "Perimeter is: $(echo "2*3.14*$r"|bc)units "

#3 Gross salary 
# DA 1.65%, HRA 0.30% of basic salary 
echo "Enter Basic salary:"
read sal 
echo "Gross salary is Rs. $(echo "0.0165 * $sal + 0.003 * $sal + $sal" |bc)"

#4 calculate mean salary 
val=$(echo 1200+1400+1350+1800 |bc)
val=$(echo $val/4 |bc)
echo "Mean basic Salary is : $val"
