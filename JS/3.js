/*
HTML : 웹 페이지의 구조를 나타냄
CSS : 웹 페이지 안에 존재하는 요소들의 스타일을 나타냄
JS : JS로직을 통해 문서의 구조와 스타일에 변화를 줄 수 있음
브라우저에서는 Javascript에서 HTML, CSS에 접근할 수 있는 API를 제*/

/*
DOM : protocol , Tree 형태
HTML 태그, parent tag, children tag
Element API: next~prev~Element-Sibling
parentNode, children
*/

/*
한번에 접근 어떻게 ?

var t =document.getElementById("lyricist");
t.style.fontSize ="9pt"
t.style.color = "blue"
t.innerHTML = "<strong>작사:</strong> <i>순구</i>"
t.innerText
t.getAttribute("src")
t.setAttribute("height", "100pt")

document.querySelectorAll("")

hr = document.createElement("hr");
cloneNode, remove, insertBefore, appendChild
*/

/*
	Callback : 나중에 호출
	setTimeout :Ticker
	setInterval :Stopwatch
	timeID 반환, clear 할 때 등
	clearTimeout, clearInterval

	EventHandler
	form, window, mouse, key
	form = 문서에 변화가 생겼을 때
	window = 모두 로드 됐을 

	Eventhandler return false ;
	t.addEventListener("submit", b);
	t.removeEventListner();
	여러 개의 이벤트 핸들러 
	기능 비활성화
*/

/*  AJAX 
	브라우저에서 페이지를 이동하지 않고 자바스크립트를 통해 HTTP Request를 보내고 받아 JS에서 처리할 수 있음
	사용자에게 더 나은 사용 경험 제공, 대부분의 웹사이트에서 사용되고 있는 기술

	비동기, send 결과가 완료되면 실행되는 이벤트 핸들러를 등록
	XMLHttpRequest();
	open, send, 0~4 readyState() => readyStateHandler
	callback
	onreadystatechange = (){this.readyState, this.status}
	status = 200, 404, 500 ...

	JSON -> Javascript object notification 
	자바스크립트의 object를 문자열 형태로 표현 
	JSON.stringify(obj) => ;
	JSON.parse("{hi:1, see:\"sss\"}"); 

	AJAX + JSON 
	

*/

//var newContent = prompt("javscript");
//document.body.innerText = newContent;