const lrcArr= lrcData.split('\n');

const res = [];
const dom = {
  audio: document.querySelector('audio'),
  ul: document.querySelector('ul'),
  container: document.querySelector('.container'),
  li: document.querySelector('.container ul li')
}

/**
 * 解析歌词并放进res数组
 * 歌词出现的时间
 * 歌词
 */
function parseLrc(){
  for(let i=1;i<lrcArr.length-1;i++){
    const lineData = lrcArr[i].split(']');
    const timeLength = lineData[0].substring(1,3)*60+(+lineData[0].substring(4));
    res.push({
      time: timeLength,
      words: lineData[1]
    })
  }
  const frag = document.createDocumentFragment();
  for(let i =0;i<res.length;i++){ //渲染歌词
    const li = document.createElement('li');
    li.textContent = res[i].words;
    frag.appendChild(li);
  }
  dom.ul.appendChild(frag);
}

/**
 * 
 * @returns 当前播放歌词索引
 */
function findIndex(){
  const curTime = dom.audio.currentTime;
  for(let i =0;i<res.length;i++){
    if(curTime<res[i].time){ return i-1; }
  }
  return res.length-1;
}

function setOffPosition(){
  const offHeight = findIndex()*dom.ul.children[1].clientHeight + dom.ul.children[1].clientHeight/2 - dom.container.clientHeight/2;
  if(offHeight<0) return 0;
  if(offHeight> dom.ul.clientHeight-dom.container.clientHeight/2) return dom.ul.clientHeight-dom.container.clientHeight/2 
  return offHeight;
}

function control(){
  dom.ul.style.transform = `translateY(-${setOffPosition()}px)`;
  const actived = document.querySelector('.active');
  if(actived){ actived.classList.remove('active');} 
  const li = dom.ul.children[findIndex()];
  if(li){
    li.classList.add('active');
  }
}

parseLrc();

dom.audio.addEventListener('timeupdate',control);
