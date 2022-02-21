console.log("HSG");
console.log("sfdsdf", "ksdfsdf");
alert("love");
var who = prompt("who");
typeof()

NaN, Infinity
a = parseInt(prompt("s"));
var obj = {}

Math.pow(2, 1);
Math.sqrt(4);
Math.random() * 100 ;
var b = parseInt(Math.random()*100);

function foo(a, b){
	return a + b;
}

who.length ;
who.substring(1,5);
who.substr(1, who.length - 3);

arr.push();
arr.pop();
arr.shift(); //<<
arr.unshift(); //>>
arr1.concat(arr2);

var str="1,2,3,4,5";
arr = str.split(",");

for(var i = 0 ; i < 5 ;i++){}
for(var i in arr){
	console.log(arr[i]);
}

function foo(a, b){
	console.log(this);
	function bar(c, d){
		return a+b+c+d ;
	}
	return bar(a+1,b+2);
}

function setName(name){
	this.name = name ;
	console.log(this);
}

var o = {name: "object", met: foo, set: setName};
var o2 = {name: "ss", met: foo, set: setName};
foo();
o.met();
o2.met();




function makeCounterFunction(initVal){
	var count = initVal ; // Environment
	function Increase(){
		count++;
		console.log(count);
	}
	return Increase ;
}

var counter1 = makeCounterFunction(0);
var counter2 = makeCounterFunction(10);

counter1();
counter2();
