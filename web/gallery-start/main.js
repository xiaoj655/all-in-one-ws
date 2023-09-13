const section = document.querySelector('section');

let para1 = document.createElement('p');
let para2 = document.createElement('p');
let motherInfo = 'The mother cats are called ';
let kittenInfo;
const requestURL = 'https://mdn.github.io/learning-area/javascript/oojs/tasks/json/sample.json';

fetch(requestURL)
  .then(response => response.text())
  .then(text => displayCatInfo(text))

function displayCatInfo(catString) {
  let total = 0;
  let male = 0;

// Add your code here
  let text = JSON.parse(catString);
  let sumKittys=0;
  let f=0;
  for(let i=0;i<2;i++){
    motherInfo += text[i].name + ' and ';
    sumKittys += Number(text[i].kittens.length);
    for(let k=0;k<text[i].kittens.length;k++){
      if(text[i].kittens[k].gender === 'f') f++;
    }
  }
  sumKittys += text[2].kittens.length;
  for(let k=0;k<text[2].kittens.length;k++){
    if(text[2].kittens.gender === 'f') f++;
  }
  kittenInfo = 'The sum of kittens is ' + sumKittys;
  kittenInfo += "female: " + f + "male: " + (sumKittys-f);
  motherInfo += text[2].name + '.';
  console.log(text);
  
// Don't edit the code below here!

  para1.textContent = motherInfo;
  para2.textContent = kittenInfo;
}

section.appendChild(para1);
section.appendChild(para2);
    