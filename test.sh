run_filler () {
	cd resources
	./filler_vm -p1 ../pdoherty.filler -p2 players/$1.filler -f maps/map0$2 | grep "fin"
	cd ..
}

players=( "abanlin" "carli" "champely" "grati" "hcao" "superjeannot" )

for i in "${players[@]}"
do
	for j in 0 1 2
	do
		echo "$i with map 0$j:"
		for k in 1 2 3 4 5
		do
			run_filler $i $j
		done
	done
done
