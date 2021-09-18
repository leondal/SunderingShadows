//ACTIVELY USED

//recite_d

#include <std.h>
#define SAVE_DIR "/d/save/stories/"+

inherit DAEMON;

// Modified the tell function to allow bards to change their speech mid-lore
// Lines 125 - 130 Lujke 24 March 2007

// Updated so they can now use emoteat, it'll automatically asume themselves to 
// be the target to prevent it bugging. -Ares 7/17/07

// Added some new functions to edit lore -Ares 4/21/06
void edit_story(string name, object tp);
void edit_song(string name, object tp);
void pre_edit(string *lines,string file,object tp,int num);
void edit_zero(string *lines,string file,object tp);
void edit_one(string line_num,string *lines,string file,object tp);
void edit_two(string line,string line_num,string *lines,string file,object tp);
void confirm_edit(string str,string line,int line_num,string *lines, string file, object tp);

void create(){
   ::create();
}

void save_story(string story, string name, object tp){
   string player = tp->query_name();
   if(!pointerp(get_dir(SAVE_DIR player+"/"))){
      mkdir(SAVE_DIR player);
      mkdir(SAVE_DIR player+"/story");
      mkdir(SAVE_DIR player+"/songs");
   }
   if(file_exists(SAVE_DIR player+"/story/"+name)){
      tell_object(tp,"Do you wish to replace the existing story "+name+"?(Y/N)");
      input_to("confirm_write",story,SAVE_DIR player+"/story/"+name); 
   } else {
      write_file(SAVE_DIR player+"/story/"+name,story);
   }
}

void confirm_write(string str, string value, string file){
   if(lower_case(str) == "y"){
      rm(file);
      write_file(file,value);
   }
}

void save_song(string song, string name, object tp){

   string player = tp->query_name();
   if(!pointerp(get_dir(SAVE_DIR player+"/"))){
      mkdir(SAVE_DIR player);
      mkdir(SAVE_DIR player+"/story");
      mkdir(SAVE_DIR player+"/songs");
   }                 
   if(file_exists(SAVE_DIR player+"/songs/"+name)){
      tell_object(tp,"Do you wish to replace the existing song "+name+"?(Y/N)");
      input_to("confirm_write",song,SAVE_DIR player+"/songs/"+name); 
   } else {
      write_file(SAVE_DIR player+"/songs/"+name,song);
   }

}

void sing(string * lines, object tp, string command){
   string line, *words, com,real_name,known_as;
   if(!sizeof(lines)) return;
   real_name = tp->query_true_name();
   known_as = tp->knownAs(real_name);
   if(sizeof(tp->query_attackers())) {
      return;
   }
   if(tp->query_property("stop recite")){

      tp->remove_property("stop recite");
      return;
   }
   line = lines[0];
   lines = lines[1..(sizeof(lines)-1)];
   words = explode(line, " ");
   if(!sizeof(words)){
      call_out("sing",5,lines,tp,command);
      return;
   }
   com = words[0];
   if(com == "sing"){
      command = "sing";

   } else if(com == "emote"){
      command = "emote";
   } 
   else if(com == "emoteat"){
	   command = "emoteat";
	   line = replace_string(line,"emoteat","emoteat "+known_as+"");
   } else {
      line = command +" "+line;
   }
   tp->force_me(line);
   call_out("sing",5,lines,tp,command);
}

void tell(string * lines, object tp, string command){
   string line, *words, com,real_name,known_as;
   if(!sizeof(lines)) return;
   real_name = tp->query_true_name();
   known_as = tp->knownAs(real_name);
   line = lines[0];
   if(sizeof(tp->query_attackers())) {
      return;
   }

   if(tp->query_property("stop recite")){

      tp->remove_property("stop recite");
      return;
   }
   lines = lines[1..(sizeof(lines)-1)];
   words = explode(line, " ");
   if(!sizeof(words)){
      call_out("tell",5,lines,tp,command);
      return;
   }
   com = words[0];
   if(com == "say"){
      command = "say";

   } else if(com == "emote"){
      command = "emote";
   } else if (com == "speech"){//added by Lujke to allow bards to change
      tp->force_me(line);      //their speech as part of a performance.
      tell(lines,tp,command);
      return;
   } else if(com == "emoteat"){
	   command = "emoteat";
	   line = replace_string(line,"emoteat","emoteat "+known_as+"");
   }
   else {
      line = command +" "+line;
   }
   tp->force_me(line);
   call_out("tell",5,lines,tp,command);
}

void sing_song(string name, object tp){
   string player;
   string file;
   string * lines;
   tp->remove_property("stop recite");
   player = tp->query_name();
   file = read_file(SAVE_DIR player+"/songs/"+name);
   lines = explode(file,"\n");
   sing(lines, tp, "sing");
}

void tell_story(string name, object tp){

   string player;
   string file;
   string * lines;
   tp->remove_property("stop recite");
   player = tp->query_name();
   file = read_file(SAVE_DIR player+"/story/"+name);
   lines = explode(file,"\n");
   tell(lines, tp, "say");
   
}

void review_story(string name, object tp){

  string player = tp->query_name();
  if(!pointerp(get_dir(SAVE_DIR player+"/"))){
    mkdir(SAVE_DIR player);
    mkdir(SAVE_DIR player+"/story");
    mkdir(SAVE_DIR player+"/songs");
  }
  if(file_exists(SAVE_DIR player+"/story/"+name)){
    tp->more(SAVE_DIR player+"/story/"+name);
  } else {
    write("No such story available.");
  }
}

void review_song(string name, object tp){


  string player = tp->query_name();
  if(!pointerp(get_dir(SAVE_DIR player+"/"))){
    mkdir(SAVE_DIR player);
    mkdir(SAVE_DIR player+"/story");
    mkdir(SAVE_DIR player+"/songs");
  }
  if(file_exists(SAVE_DIR player+"/songs/"+name)){
    tp->more(SAVE_DIR player+"/songs/"+name);
  } else {
    write("No such song available.");
  }
}

void delete_story(string name, object tp){

   string player = tp->query_name();
   if(!pointerp(get_dir(SAVE_DIR player+"/"))){
      mkdir(SAVE_DIR player);
      mkdir(SAVE_DIR player+"/story");
      mkdir(SAVE_DIR player+"/songs");
   }
   if(file_exists(SAVE_DIR player+"/story/"+name)){
      rm(SAVE_DIR player+"/story/"+name);
   }
}

void delete_song(string name, object tp){


   string player = tp->query_name();
   if(!pointerp(get_dir(SAVE_DIR player+"/"))){
      mkdir(SAVE_DIR player);
      mkdir(SAVE_DIR player+"/story");
      mkdir(SAVE_DIR player+"/songs");
   }
   if(file_exists(SAVE_DIR player+"/songs/"+name)){
      rm(SAVE_DIR player+"/songs/"+name);
   }
}

void edit_story(string name, object tp){
   string player;
   string file;
   string file_name;
   string * lines;
   tp->remove_property("stop recite");
   player = tp->query_name();
   file_name = SAVE_DIR player+"/story/"+name;
   if(!file_exists(file_name))
   {
       write("Not a story, try again.");
       return;
   }
   file = read_file(SAVE_DIR player+"/story/"+name);
   lines = explode(file,"\n");
   pre_edit(lines,file_name,tp,0);
}

void edit_song(string name, object tp){
   string player;
   string file;
   string file_name;
   string * lines;
   tp->remove_property("stop recite");
   player = tp->query_name();
   file_name = SAVE_DIR player+"/songs/"+name;
   if(!file_exists(file_name))
   {
       write("Not a song, try again.");
       return;
   }
   file = read_file(SAVE_DIR player+"/songs/"+name);
   lines = explode(file,"\n");
   pre_edit(lines,file_name,tp,0);
}

void pre_edit(string *lines,string file,object tp,int num)
{
    int i;
    function hold;
    string *show_lines=({}),tmp;
    if(!pointerp(lines))    { return; }
    if(!stringp(file))      { return; }
    if(!objectp(tp))        { return; }

    tmp = read_file(file);
    show_lines = explode(tmp,"\n");
    for(i=0;i<sizeof(show_lines);i++)
    {
        show_lines[i] = "%^CYAN%^"+arrange_string(""+i+":",5)+"%^RESET%^"+show_lines[i]+"";
    }

    hold = call_other(TO, "edit_zero",lines,file,tp);     
    tp->more(show_lines,"",hold);
    return;
}

void edit_zero(string *lines,string file,object tp)
{
    write("Input the line number you wish to edit.");
    write("Type ** or none to abort.");
    input_to("edit_one",lines,file,tp);
    return;
}

void edit_one(string str,string *lines,string file,object tp)
{
    int line_num;
    if(!stringp(str))       { return; }
    if(!pointerp(lines))    { return; }
    if(!stringp(file))      { return; }
    if(!objectp(tp))        { return; }

    if(str == "**" || str == "none" || str == "" || str == " ") 
    {
        write("Aborting...\n");
        return;
    }

    line_num = to_int(str);
    if(!intp(line_num))
    {
        write("Bad line number, aborting...");
        return;
    }
    if(line_num < 0 || line_num > (sizeof(lines)-1))
    {
        write("Bad line number, aborting...");
        return;
    }
    write("%^BOLD%^%^BLUE%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    write("%^RESET%^%^BOLD%^  Editing line %^CYAN%^"+line_num+"\n%^RESET%^");
    write("    %^RESET%^"+lines[line_num]+"\n");
    write("  Please enter this line the way you would like for it to be seen");
    write("  Enter ** or hit return to abort.  Type <delete> to delete the line.");
    input_to("edit_two",str,lines,file,tp);
    return;
}

void edit_two(string line,string num,string *lines,string file,object tp)
{
    int line_num;
    if(!stringp(line))      { return; }
    if(!stringp(num))       { return; }
    if(!pointerp(lines))    { return; }
    if(!stringp(file))      { return; }
    if(!objectp(tp))        { return; }
    line_num = to_int(num);

    if(line == "**" || line == "" || line == " ")
    {
        write("Aborting...");
        return;
    }

    else if(line == "delete")
    {
        write("Delete line "+line_num+"?");
        write("Please enter yes or no.");
        lines -= ({ lines[line_num] });
        input_to("confirm_edit",line,line_num,lines,file,tp);
        return;
    }
    else 
    {
        write("Line number "+line_num+" changed to:\n");
        write("  "+line);
        write("\nIs this correct?  Enter yes or no.");
        lines[line_num] = line;
        input_to("confirm_edit",line,line_num,lines,file,tp);
        return;
    }
    return;
}

void confirm_edit(string str,string line,int line_num,string *lines, string file, object tp)
{
    string story;
    if(!stringp(str))       { return; }
    if(!stringp(line))      { return; }
    if(!intp(line_num))     { return; }
    if(!pointerp(lines))    { return; }
    if(!stringp(file))      { return; }
    if(!objectp(tp))        { return; }
    story = implode(lines,"\n");

    if(lower_case(str) == "no" || lower_case(str) == "")
    {
        write("Aborting...");
        return;
    }
    else if(lower_case(str) == "yes")
    {
        write("Saving changes...");
        rm(file);
        write_file(file,story);
        return;
    }
    return;
}
