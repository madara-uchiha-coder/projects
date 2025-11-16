let express= require("express");
let app = express();
let db=require("./mongo");
let path=require("path")
const cors = require("cors");
app.use(cors());
let mongoose=require("mongoose")
app.use(express.json())
app.use(express.static(path.join(__dirname, "static")));
app.use(express.urlencoded({ extended: true }));
app.get("/",(req,res)=>{
res.sendFile(path.join(__dirname,"static","login.html"));
})
app.post("/login",(req,res)=>{
    let{email,password}=req.body;
    let enq=new db({
email:email,
password:password
})
enq.save().then(()=>{
console.log("data saved")
console.log(req.body)
})
})


const connectionString = 'mongodb://localhost:27017/mydatabase'; 
mongoose.connect(connectionString)
  .then(() => {
    console.log('MongoDB connected successfully!');
  })
  .catch(err => {
    console.error('MongoDB connection error:', err);
  });


  app.listen(8000);