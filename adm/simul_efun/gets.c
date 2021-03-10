string gets(){
   return new(base_name(this_object()))->getInput();

}

int flag = 0;
string input;

string getInput(){
   input_to("procInput");
   while(!flag){
   }
   return input;
}

void procInput(string xxx){
   input = xxx;
   flag = 1;
   destruct(this_object());
}
