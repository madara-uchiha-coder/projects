let express=require("express");
let app=express();
app.use(express.json());
let model=require("./connection")
app.use(express.urlencoded({ extended: true }));
const path = require('path');
const mongoose=require("mongoose");
app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "index.html"));
});
app.post("/login",(req,res)=>{
    let {username,email}=req.body;
    let enq=new model({
username:username,
email:email
})
enq.save().then(()=>{
console.log("data saved")
console.log(username,email)
})})



let connect=()=>{  
mongoose.connect('mongodb://127.0.0.1:27017/test')
  .then(() => console.log('Connected!'));
}
connect()
app.listen(3000)