// 设置画布

const canvas = document.querySelector('canvas');
const ctx = canvas.getContext('2d');

const width = canvas.width = window.innerWidth;
const height = canvas.height = window.innerHeight;

// 生成随机数的函数

function random(min,max) {
  const num = Math.floor(Math.random() * (max - min)) + min;
  return num;
}

// 生成随机颜色值的函数

function randomColor() {
  const color = 'rgb(' +
                random(0, 255) + ',' +
                random(0, 255) + ',' +
                random(0, 255) + ')';
  return color;
}

// 定义 Ball 构造器

function Shape(x, y, velX, velY, exists) {
  this.x = x;
  this.y = y;
  this.velX = velX;
  this.velY = velY;
  this.exists = exists;
}

function Ball(color,size,x, y,velX, velY, exists){
  Shape.call(this, x, y, velX, velY, exists);
  
  this.color = color;
  this.size = size;
}

Ball.prototype = Object.create(Shape.prototype);
Ball.prototype.constructor = Ball;

function EvilCircle(x, y, exists) {
  Shape.call(this, x, y, 20, 20, exists);

  this.color = 'white';
  this.size = 10;
}

EvilCircle.prototype = Object.create(Shape.prototype);
EvilCircle.prototype.constructor = EvilCircle;

EvilCircle.prototype.draw = function() {
  ctx.beginPath();
  ctx.strokeStyle = this.color;
  ctx.arc(this.x, this.y, this.size, 0, 2 * Math.PI);
  ctx.stroke();
};

EvilCircle.prototype.checkBounds= function() {
  if((this.x + this.size) >= width) {
    this.size = width - this.x;
  }

  if((this.x - this.size) <= 0) {
    this.size = this.x;
  }

  if((this.y + this.size) >= height) {
    this.size = height-this.y;
  }

  if((this.y - this.size) <= 0) {
    this.size = this.y;
  }

};
EvilCircle.prototype.setControls= function () {
  window.onkeydown = (e) => {
    switch (e.key) {
      case "a":
        this.x -= this.velX;
        break;
      case "d":
        this.x += this.velX;
        break;
      case "w":
        this.y -= this.velY;
        break;
      case "s":
        this.y += this.velY;
        break;
    }
  };
}

EvilCircle.prototype.collisionDetect = function() {
  for(let j = 0; j < balls.length; j++) {
    const dx = this.x - balls[j].x;
    const dy = this.y - balls[j].y;
    const distance = Math.sqrt(dx * dx + dy * dy);

    if (distance < this.size + balls[j].size) {
      balls[j].exists = false;
    }
  }
};

// 定义彩球绘制函数

Ball.prototype.draw = function() {
  ctx.beginPath();
  ctx.fillStyle = this.color;
  ctx.arc(this.x, this.y, this.size, 0, 2 * Math.PI);
  ctx.fill();
};

// 定义彩球更新函数

Ball.prototype.update = function() {
  if((this.x + this.size) >= width) {
    this.velX = -(this.velX);
  }

  if((this.x - this.size) <= 0) {
    this.velX = -(this.velX);
  }

  if((this.y + this.size) >= height) {
    this.velY = -(this.velY);
  }

  if((this.y - this.size) <= 0) {
    this.velY = -(this.velY);
  }

  this.x += this.velX;
  this.y += this.velY;
};

// 定义碰撞检测函数

Ball.prototype.collisionDetect = function() {
  for(let j = 0; j < balls.length; j++) {
    if(this !== balls[j]) {
      const dx = this.x - balls[j].x;
      const dy = this.y - balls[j].y;
      const distance = Math.sqrt(dx * dx + dy * dy);

      if (distance < this.size + balls[j].size) {
        balls[j].color = this.color = randomColor();
      }
    }
  }
};

// 定义一个数组，生成并保存所有的球

let balls = [];

while(balls.length < 25) {
  const size = random(10,20);
  let ball = new Ball(
    // 为避免绘制错误，球至少离画布边缘球本身一倍宽度的距离
    randomColor(),
    size,
    random(0 + size, width - size),
    random(0 + size, height - size),
    random(-7, 7),
    random(-7, 7),
    true
  );
  balls.push(ball);
}

// 定义一个循环来不停地播放

const size = random(10,20);
let EvilC = new EvilCircle(
    random(0 + size, width - size),
    random(0 + size, height - size),
    true
);
EvilC.setControls();


const p = document.createElement('p');
p.style.color = 'white';

const h1 = document.querySelector('h1');

function loop() {
  EvilC.draw();
  EvilC.checkBounds();
  EvilC.collisionDetect();

  ctx.fillStyle = 'rgba(0,0,0,0.25)';
  ctx.fillRect(0,0,width,height);

  let cnt =0;
  for(let i = 0; i < balls.length; i++) {
    if(balls[i].exists){
      cnt++;
      balls[i].draw();
      balls[i].update();
      balls[i].collisionDetect();
    }
  }

  p.innerHTML = cnt;
  h1.appendChild(p);


  requestAnimationFrame(loop);
}

loop();
