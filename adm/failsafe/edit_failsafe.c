//
//  Basic editor object
//
// Zak, 930129:
//  - if using ed and the file is not modified (i.e, Q pressed, for
//    example), it will abort as the simple editor does when ~q entered
//    (I'm sick of not having an abort in ed when mailing/posting...)
//
// Watcher, 930228
//  - Added ~r, ~w, and ~h commands to the editor and allow '**' as
//    optional edit closer (for those use to the old system)

#define EDITOR_TAIL 1000
void display_ed_help();

private static string edit_filename, callback;
private static mixed edit_args;
private static object act_ob;
private static int mtime;

varargs int edit (string fname, string fun, object ob, mixed args) {
  string tmp,cut_tmp;
  mixed *stat_buf;
  int length, limit_length;
  
  callback = fun;
  edit_args = args;
  if (!ob) ob = this_player();
  act_ob = ob;
  if(!fname) {
    message("system", "No file name passed to edit.", this_player());
    return 0;
  }
  tmp = read_file (fname);
  if (!write_file(fname,"")) {
    message("system", "Edit cannot write to "+fname+".", this_player());
    return 0;
  }
  edit_filename = fname;
  if ((string)this_player()->query_env("editor") == "ed") {
    stat_buf = stat( fname, -1 );
    mtime = (int) stat_buf[ 1 ];
    ed (edit_filename, "stop_ed");
    this_player()->set_is_editing(fname + " (Edit object)");
    return 1;
  }
  message("system", "To end message type \".\".  To abort, type ~q.  "
	  "To view help, type ~h.", this_player());
  message("system", "____________________________________________________"
	  "_____________", this_player());
  if(tmp) {
    if((length=strlen(tmp)) > EDITOR_TAIL) {// Max is about 8191 characters. Much less is needed for spam control
      message("Nsystem","WARNING: Only showing the last bit...  Recommend you use the expanded editor! (~e)", this_player());
      limit_length = length - EDITOR_TAIL;
      cut_tmp= tmp[limit_length..length];
      message("Nsystem", cut_tmp, this_player());
    } else {
      message("Nsystem", tmp, this_player());
    }
  }
  this_player()->set_is_editing(fname + " (Edit object)");
  input_to("lines");
  return 1;
}

static void lines(string str) {
   string file;
 
   if (str == "." || str == "**") {
      this_player()->set_is_editing("");
      if (act_ob && function_exists(callback,act_ob)) {
	call_other(act_ob,callback,edit_args);
      }
      else message("system", "Cannot find function "+callback, this_player());
      return;
   }
   if (str == "~e") {
      ed(edit_filename,"stop_ed");
      return;
   }
   if (str == "~q") {
      message("system", "Edit aborted.", this_player());
      this_player()->set_is_editing("");
      if (act_ob && function_exists ("abort",act_ob))
         act_ob->abort();
      return;
   }
   if (str == "~p") {
 
	  if(!file_exists(edit_filename) || !read_file(edit_filename)) 
          message("system", "Buffer empty.", this_player());
 
          else message("Nsystem", read_file(edit_filename)+"\n",this_player());
 
	  input_to("lines");
	  return;
   }

   if (str == "~r" || str == "~w") {
        message("system", "No file name given.", this_player());
	input_to("lines");
	return;
   }
 
   if(wizardp(this_object()) && sscanf(str, "~r %s", file) == 1) {
 
   	file = resolv_path("cwd", file);

	if(!file_exists(file)) {
        message("system", sprintf("No such file: %s", file), this_player());
	input_to("lines");
	return; }
 
	if((int)master()->valid_read(file, this_object()) == 0) {
        message("system", sprintf("%s: Access denied.", file), this_player());
	input_to("lines");
	return; }
 
	write_file(edit_filename, read_file(file));
        message("system", sprintf("%s appended.", file), this_player());
	input_to("lines");
	return;

   }
 
   if(wizardp(this_object()) && sscanf(str,"~w %s", file) == 1) {

 	file = resolv_path("cwd", file);
 
	if((int)master()->valid_write(file, this_object()) == 0) {
        message("system", sprintf("%s: Write access denied.", file),
          this_player());
	input_to("lines");
	return; }

	if(file_exists(file))
          message("system", sprintf("Buffer appended to %s.", file),
            this_player());
        else message("system", sprintf("Buffer written to %s.", file),
          this_player());
 
	write_file(file, read_file(edit_filename));
	input_to("lines");
	return;
 
   }
 
 
   if(str == "~h" || str == "~help") {
	display_ed_help();
	input_to("lines");
	return;
   }
 
   write_file(edit_filename,str + "\n");
   input_to("lines");
   return;
}

void stop_ed() {
   mixed *statbuf;

   this_player()->set_is_editing("");
   statbuf = stat( edit_filename, -1 );
   if ( mtime == statbuf[ 1 ] ) {
      message("system", "Edit aborted.", this_player());
      if (act_ob && function_exists ("abort",act_ob))
         act_ob->abort();
      return;
   }
   if (act_ob && function_exists(callback,act_ob))
     call_other(act_ob,callback, edit_args);
   else
      message("system", "*Error could not find target object when leaving ed.",
        this_player());
   return;
}

string query_edit_filename() {
   return edit_filename;
}

void set_edit_filename(string str) {
   edit_filename = str;
   return;
}
 
void display_ed_help() {

   message("system", "\nStandard User Editor\n====================\n\n"
	 "\t~e\t- Enter expanded editor system\n"
	 "\t~h\t- This editor help display\n"
	 "\t~p\t- Display contents of editor buffer\n"
	 "\t~q\t- Abort editor without saving contents", this_player());
 
   if(wizardp(this_object()))
   message("system", "\n\t~r [file]\t- Read contents of file into editor\n"
	 "\t~w [file]\t- Write editor buffer to file\n", this_player());
 
   message("system", "\n\tExit and save with \".\" or \"**\".\n", this_player());

return; }
 
