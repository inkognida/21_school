package main

import (
	"fmt"
	"math"
	"runtime"
	"time"
)

func add(x, y int)  int{
	return x + y
}

func swap(x, y string) (string, string){
	return y, x
}

func split(sum int) (x, y int) {
	x = sum * 4 / 9
	y = sum - x
	return
}

var c, python, java bool
var i, j int = 1, 2
const Pi = 3.14

const (
	Big = 1 << 100
	Small = Big >> 99
)

func needInt(x int) int { return  x * 10 + 1}
func needFloat(x float64) float64 { return x * 0.1 }


func sqrt(x float64) string {
	if x < 0{
		return sqrt(-x) + "i"
	}
	return fmt.Sprint(math.Sqrt(x))
}

func pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		return v
	}
	return lim
}

func else_pow(x, n, lim float64) float64 {
	if v := math.Pow(x, n); v < lim {
		return v
	} else {
		fmt.Printf("%g >= %g\n", v, lim)
	}
	return lim
}

func my_sqrt(x float64) string {
	z := float64(1)
	for i := 0; i < 11; i++ {
		z -= (z * z - x) / (2 * z)
	}
	return fmt.Sprint("aboba \t", z)
}


func main() {

	fmt.Println(sqrt(2))
	fmt.Println(my_sqrt(2))

	fmt.Println("\n\naboba", math.Sqrt(123))
	fmt.Println(add(10,20))
	a, b := swap("hello", "world")
	fmt.Println(a, b)

	fmt.Println(split(17))

	//var i int

	fmt.Println(i, c, python, java)

	var c, python, java = true, false, "no!"
	fmt.Println(i, j, c, python, java)


	var i, j int = 1, 2
	k := 3
	fmt.Println(i, j, k)



	var i_null int
	var f float64
	var b_null bool
	var s string
	fmt.Printf("%v %v %v %q\n", i_null, f, b_null, s) //differs from Println


	var x,y int = 3, 4
	var ff float64 = math.Sqrt(float64((x*x + y*y)))
	var z uint = uint(ff)
	fmt.Println(x, y, z)

	v := 42
	fmt.Printf("%v is of type %T\n", float64(v) * 0.01) //change original variable


	const World = "aboba"

	fmt.Println("Hi", World)
	fmt.Println("Happy", Pi, "day")

	const Tru = true
	fmt.Println("Any", Tru, "rules", "?") //Println add a space between args


	fmt.Println(needInt(Small))
	fmt.Println(needFloat(Small))
	fmt.Println(needFloat(Big))
	//fmt.Println(needInt(Big)) doesnt work because of overlaping int

	//fmt.Printf("%v\n", 1 << 100 >> 99)

	//var sum_loop int   //or
	//sum_loop := 0
	//for i := 0; i < 2; i++{
	//	sum_loop += i
	//}
	//fmt.Printf("%v\n", sum_loop)



	sum := 1
	for ; sum < 100; {
		sum += sum
	}
	fmt.Println(sum)

	qwe := 1
	for qwe < 100 {
		qwe += qwe
	}
	fmt.Println(qwe)

	fmt.Println(sqrt(4), sqrt(-4))

	//Print - take a string and print it
	//Printf - print formatter (obvious printf)
	//Println - similar to Printf, but append a newline char \n

	fmt.Println(pow(3, 2, 10), pow(3, 3, 20))
	fmt.Println(else_pow(3, 2, 10), else_pow(3, 2, 20))

	fmt.Print("Go runs on ")
	switch os := runtime.GOOS; os {
	case "darwin":
		fmt.Println("OS X")
	default:
		fmt.Printf("%s\n", os)
	}

	fmt.Println("When's Saturday?")
	today := time.Now().Weekday();
	switch time.Saturday {
	case today + 0:
		fmt.Println("Today.")
	case today + 1:
		fmt.Println("Tomorrow")
	default:
		fmt.Println("Aboba (you need to wait for it)")
	}

	t := time.Now()
	switch {
	case t.Hour() < 12:
		fmt.Println("Good morning!")
	case t.Hour() < 17:
		fmt.Println("Good afternoon!")
	default:
		fmt.Println("Good evening")
	}

	//defer fmt.Println("world") //done after next rows
	//
	//fmt.Println("hello")


	fmt.Println("counting")
	for i := 0; i < 10; i++ {
		defer fmt.Println(i)
	}
	fmt.Println("done")
}
