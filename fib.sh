a=0
b=1

temp=0

n=$1
i=1
echo $a
echo $b
while [ $i -le $n ]
do 
	temp=$(($a + $b))
	echo $temp;
	a=$b
	b=$temp
	let i++;
	
done
