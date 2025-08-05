let fs = require('fs'.Promise);

const temp_promise = new Promise((resolve,reject)=>{
     fs.readFile('temp.txt','utf-8',(err,data)=>{
        if(err)
            reject(err);
        else
            resolve(data);
     })
})
temp_promise
.then((data)=>{
    console.log(data);
    })
.catch((err)=>{
    console.log(err);
    }) ;