
function logClass(target: any) {
    console.log(target.name);
}

@logClass
class myClass {
}

const a = new myClass();