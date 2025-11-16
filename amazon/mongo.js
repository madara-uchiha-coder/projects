let mongoose=require("mongoose");
let data=mongoose.Schema({
    email:{
        type:String,
        required:true,
        // unique:true,
        sparse: true
    },
    password:{
        type:String,
        required:true
    }
})
let model=mongoose.model("user",data);
module.exports=mongoose.model("user",data);