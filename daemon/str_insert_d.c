//ACTIVELY USED
//Should just be a simul-efun

//coded by Lujke August 2016
//brute_insert_string("123456789", "hello", 4)
// returns "1234hello56789"
string brute_insert_string(string str, string insert, int pos){
  string pre, post; 
  if(!stringp(str)){return "error";}
  if(!stringp(insert)){return str;} 
  if (pos>strlen(str)-1){
    return str;
  }
  pre = str[0..pos]; 
  post = str[pos+1..strlen(str)]; 
  return pre + insert + post;
}
//insert_string("123456789", "hello", 3) 
// returns "123hello9"
string insert_string(string str, string insert, int pos){
  string pre, post; 
  if(!stringp(str)){return "error";}
  if(!stringp(insert)){return str;} 
  if (pos>strlen(str)-1){ return str;}
  pre = str[0..pos]; 
  post = str[pos+strlen(insert)+1..strlen(str)]; 
  return pre + insert + post;
}
