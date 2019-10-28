valgrind --tool=tracergrind --output=cpu-bound.trace ./cpu-bound 1 0.12
$((16#$ADDRESS))texttrace cpu-bound.trace out.texttrace
cat out.texttrace | grep "[M]" > out2.txt

while read line; do
	ADDRESS=$(echo $line | awk '{ print $7 }')
	DECIMAL=$((16#$ADDRESS))
	if [ $DECIMAL -gt 67108864 -a $DECIMAL -lt 64424509440 ]; then
		echo $ADDRESS > memaccesses.txt
	fi
done <out2.txt

