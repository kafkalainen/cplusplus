#!/bin/bash

# kaf_nblen_test()
# {
# 	nb=$1
# 	option=$2
# 	answer=$3
# 	echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
# 	echo "++ TEST $nb ++"

# 	if diff <(./tester $option | cat -e) <(echo "$answer");
# 	then
# 		echo -e "OK\n"
# 	else
# 		echo -e "KO\n"
# 	fi
# }

kaf_nblen_test()
{
	nb=$1
	testable=$2
	answer=$3
	echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "++ TEST $nb ++"

	if diff -y <(./tester $testable | cat -e) <(echo "$answer");
	then
		echo -e "OK\n"
	else
		echo -e "KO\n"
	fi
}

kaf_swap_test()
{
	nb=$1
	testable1=$2
	testable2=$3
	answer=$4
	echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "++ TEST $nb ++"

	if diff -y <(./tester $testable1 $testable2 | cat -e) <(echo "$answer");
	then
		echo -e "OK\n"
	else
		echo -e "KO\n"
	fi
}

kaf_vec3_test()
{
	nb=$1
	x0=$2
	y0=$3
	z0=$4
	answer=$5
	echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "+++++++++<-YOUR OUTPUT ++ TEST $nb ++ -> TEST OUTPUT++++++++++"

	if diff -y <(./tester $x0 $y0 $z0 | cat -e) <(echo "$answer");
	then
		echo -e "OK\n"
	else
		echo -e "KO\n"
	fi
}

kaf_tri_test()
{
	nb=$1
	params=$2
	answer=$3
	echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "+++++++++<-YOUR OUTPUT ++ TEST $nb ++ -> TEST OUTPUT++++++++++"

	if diff -y <(./tester $params | cat -e) <(echo -e $answer);
	then
		echo -e "OK\n"
	else
		echo -e "KO\n"
	fi
}

g++ -o tester -Wall -Wextra -Werror -g kaf_nblen_main.cpp -I.. -L.. -lkaf
kaf_nblen_test '1' '100' '3$'
kaf_nblen_test '2' '1000' '4$'
kaf_nblen_test '3' '10000' '5$'
kaf_nblen_test '4' '100000' '6$'
kaf_nblen_test '5' '1000000' '7$'
kaf_nblen_test '6' '10000000' '8$'
g++ -o tester -Wall -Wextra -Werror -g kaf_swap_main.cpp -I.. -L.. -lkaf
kaf_swap_test '1' '100' '1' '1 100$'
g++ -o tester -Wall -Wextra -Werror -g kaf_vectors_main.cpp -I.. -L.. -lkaf
kaf_vec3_test '1' '1' '2' '3' 'x: 1 y: 2 z: 3 w: 1$'
g++ -o tester -Wall -Wextra -Werror -g kaf_triangles_main.cpp -I.. -L.. -lkaf
kaf_tri_test '1' '1 2 3 4 5 6 7 8 9' "triangle points:$\n
x: 1 y: 2 z: 3 w: 1$
x: 1 y: 2 z: 3 w: 1$"
