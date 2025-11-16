let mongoose=require("mongoose")
let obj=mongoose.Schema({
    username:String,
    email:String
})
let model=mongoose.model("user",obj);
module.exports = mongoose.model('User', obj);
