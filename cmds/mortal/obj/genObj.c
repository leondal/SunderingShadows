#include <std.h>
#include <standards.h>

inherit OBJECT;

int prof;
string file;
string type;
string material, color;
int size;
object *materialObj;

void final_check(mixed input, mapping keyMap);
void finish_object(mapping keyMap, string template);
void next_input(mapping keyMap);

int save_me(string file){
    return 1;
}

int drop(){
    return 1;
}

void set_color(string c){
    color=c;
}

void set_type(string t){
    type=t;
}

void set_size(int i){
    size = i;
}

void set_prof(int p){
    prof = p;
}

void set_material(object *o){
    int i;
    material = "";
    color = "";

    if (!pointerp(o)) {
        o = ({o});
    }
    materialObj = o;
    for (i=0;i<sizeof(materialObj);i++) {
        if (i > 0) {
            material+=" and ";
            if ((string)o[i]->query_color() != "") {
                color+=" and ";
            }
        }
        write(  o[i]->query_subtype() );
        material+=(string)o[i]->query_subtype();
        color += (string)o[i]->query_color();
    }
}

void set_file(string f){
  
  f=replace_string(f," ","_");
  f=replace_string(f,".","");
  f=replace_string(f,"\\","");
  f=replace_string(f,"/","");
  f=replace_string(f,"*","");
  f=replace_string(f,"?","");
  f=replace_string(f,"~","");
  f=replace_string(f, "\"","");
  file = f;
}

void init(){
    mapping keyMap = ([]);
    ::init();

    keyMap["~SIZE~"] = size;

    write("Please enter an unique (unused before) one word reference for this object.");
    input_to("files",0,keyMap);

}

void files(string f, mapping keyMap){
    if(!f){
        write("Please enter an unique (unused before) one word reference for this object.");
    write("Please only use underscores (_) and alphanumeric characters. Spaces are bad.");
        input_to("files",0,keyMap);
        return;
    }
    set_file(f);

    write("Please enter the name of this object.");
    input_to("names",0,keyMap);
}

void redo_files(string f, mapping keyMap){
  if(!f){
    write("Please enter an unique (unused before) one word reference for th\
is object.");
    write("Please only use underscores (_) and alphanumeric characters. Spaces are bad.");
    write("If you want to retain the previous filename ("+file+"), Enter '**'");
    input_to("redo_files",0,keyMap);
    return;
  }
  if (f == "**") {
    write("Leaving the file as is.");
  } else {
	set_file(f);
  }
  final_check(0,keyMap);
}

void names(string name, mapping keyMap){
    if (!name) {
        write("Please enter the name of this object.");
        input_to("names",0,keyMap);
        return;
    }
    name = replace_string(name, "\"", "");
    keyMap["~NAME~"] = name;
    write("Please enter the key words for this item. Separate with commas.(dagger,silver dagger,Dagger,)");
    input_to("ids",0,keyMap);
}

void redo_names(string name, mapping keyMap){
  if (!name) {
    write("Please enter the name of this object.");
    write("The current name is: "+keyMap["~NAME~"] );
    write("Input '**' to indicate no change");
    input_to("redo_names",0,keyMap);
    return;
  }
  if (name == "**") {
    write("Leaving the name as it was.");
  } else {
	name = replace_string(name, "\"", "");
    keyMap["~NAME~"] = name;
  }
  final_check(0,keyMap);
}


void ids(string id_values, mapping keyMap){
    string *id_array;
    if (!id_values) {
        write("Please enter the key words for this item. Separate with commas.(dagger,silver dagger,Dagger,)");
        input_to("ids",0,keyMap);
        return;
    }
	id_values = replace_string(id_values, "\"", "");
    id_array = explode(id_values, ",");
    id_array += ({keyMap["~NAME~"]});
    keyMap["~ID~"]=id_array;

    write("Please enter the short description, or the description you see in your inventory.");
    write("Use:");
    write(" $C for color");
    write(" $M for Material");
    write(" $T for the base type");
    write(" IE You create a cloak from red silk. You use 'A heavily embroidered flowing $C $M $T'");
    write("    Would result in A heavily embroidered flowing red silk cloak.");
    write(" NOTE: skins don't have a color so no $C is required.");
    input_to("shortDesc",0,keyMap);

}
void redo_ids(string id_values, mapping keyMap){
  string *id_array;
  if (!id_values) {
    write("Please enter the key words for this item. Separate with commas.(dagger,silver dagger,Dagger,)");
    write("ID's already assigned to the item are:"+implode(keyMap["~ID~"],"\n\t"));
    write("Enter '**' to indicate no change to the ID's");
    input_to("redo_ids",0,keyMap);
    return;
  }
  if (id_values == "**") {
    write("The keywords of the item are unchanged.");
  } else {
	id_values = replace_string(id_values, "\"", "");
    id_array = explode(id_values, ",");
    id_array += ({keyMap["~NAME~"]});
    keyMap["~ID~"]=id_array;
  }
  final_check(0,keyMap);
}


void shortDesc(string shrt, mapping keyMap){
    if (!shrt) {
        write("Please enter the short description, or the description you see in your inventory.");
        input_to("shortDesc",0,keyMap);
        return;
    }
    if (strsrch(shrt,"$C") == -1 && color != "") {
        shrt += " $C";
    }
    if (strsrch(shrt,"$M") == -1) {
        shrt += " $M";
    }
    if (strsrch(shrt,"$T") == -1) {
        shrt += " $T";
    }

    shrt = replace_string(shrt,"$C",color);
    shrt = replace_string(shrt,"$M",material);
    shrt = replace_string(shrt,"$T",type);
	shrt = replace_string(shrt, "\"", "'");
    keyMap["~SHORT~"] = shrt;


    write("Please input the Long describe >Note use ** to end the long describe.  Don't quit in this field.");
    write("If you make a mistake, a ~r on an empty line will reset the long description.");
    write("Entering multiple lines is okay.");
    write("%^BOLD%^%^RED%^Please note: If your description runs longer than 1000 characters (every things counts as a character, even spaces, enters, and color codes), your description will likely be cut off.%^RESET%^");
    write("To be safe, make sure you have no more than 15 lines of this length:");
    write("%^BOLD%^|---------------------------------------------------------------|%^RESET%^");
    input_to("long", 0,keyMap,"");
}

void redo_shortDesc(string shrt, mapping keyMap){
  if (!shrt) {
    write("Please enter the short description, or the description you see in yo\
ur inventory.");
    write("Use:");
    write(" $C for color");
    write(" $M for Material");
    write(" $T for the base type");
    write(" IE You create a cloak from red silk. You use 'A heavily embroidered\
 flowing $C $M $T'");
    write("    Would result in A heavily embroidered flowing red silk cloak.");
    write(" NOTE: skins don't have a color so no $C is required.");

    input_to("redo_shortDesc",0,keyMap);
    return;
  }
  if (shrt == "**") {
    write("Retaining present short description");
  } else { 
  if (strsrch(shrt,"$C") == -1 && color != "") {
    shrt += " $C";
  }
  if (strsrch(shrt,"$M") == -1) {
    shrt += " $M";
  }
  if (strsrch(shrt,"$T") == -1) {
    shrt += " $T";
  }

  shrt = replace_string(shrt,"$C",color);
  shrt = replace_string(shrt,"$M",material);
  shrt = replace_string(shrt,"$T",type);
  shrt = replace_string(shrt, "\"", "'");
  keyMap["~SHORT~"] = shrt;
  }

  final_check(0,keyMap);
}

void long(string str,  mapping keyMap, string longd) {
  if(!str) {
    write("Please input the Long describe for this Object.");
    write("Entering multiple lines is okay.");
    write("%^BOLD%^%^RED%^Please note: If your description runs longer than 1000 characters (every things counts as a character, even spaces, enters, and color codes), your description will likely be cut off.%^RESET%^");
    write("To be safe, make sure you have no more than 15 lines of this length:");
    write("%^BOLD%^|---------------------------------------------------------------|%^RESET%^");
    input_to("long",longd);
    return 1;
  }
  if(str == "~r"){
    write("Long reset, Please restart long description.");
    write("\n");
    input_to("long", 0,keyMap,"");
    return;
  }
  if(str != "**") {
    longd += str + "\n";
    input_to("long", 0, keyMap, longd);
    return;
  }
  longd = replace_string(longd, "\"", "'");
  keyMap["~LONG~"] = longd;
  next_input(keyMap);

}


void redo_long(string str,  mapping keyMap, string longd) {
    if(!str) {
        write("Please input the Long describe for this Object.");
	write("Enter '~r' to reset the long. '**' completes the");
	write("long description. '~q' will abort changing the long");
	write("and leave it as it was.");
	write("Entering multiple lines is okay.");

        input_to("redo_long",longd);
        return 1;
    }
    if(str == "~q") {
      write("Long description unchanged.");
    } else {
      
      if(str == "~r"){
        write("Long reset, Please restart long description.");
        write("\n");
        input_to("long", 0,keyMap,"");
        return;
      }
      if(str != "**") {
        longd += str + "\n";
        input_to("long", 0, keyMap, longd);
        return;
      }
      longd = replace_string(longd, "\"", "'");
      keyMap["~LONG~"] = longd;
    }
    final_check(0,keyMap);
}

void next_input(mapping keyMap){
    final_check(0,keyMap);
}

void final_check(mixed input, mapping keyMap) {
  string temp;
  if (!input || !stringp(input)) {
    write("Your object so far:");
    write("1> Unique pattern name: "+file);
    write("2> Name: "+keyMap["~NAME~"]);
    
    write("3> Keywords: "+ implode(keyMap["~ID~"],"\t")+".");
    write("4> Short description: "+keyMap["~SHORT~"]);
    write("5> Long description: "+keyMap["~LONG~"]);
    
    write("Input 1-5 if you wish to change one of the above.");
    write("enter \"0\" or \"done\" or \"**\" to finish the object.");
    input_to("final_check",0,keyMap);
    return;
  } else {
    switch(lower_case(input)) {
    case "0":
    case "**":
    case "done":
      write("Finishing.");
      finish_object(keyMap,"");
      break;
      
    case "1":
      write("Please enter an unique (unused before) one word reference for this object.");
      write("Please only use underscores (_) and alphanumeric characters. Spaces are bad.");
      write("If you want to retain the previous filename ("+file+"), Enter '**'");
      input_to("redo_files",0,keyMap);
      return;
      break;

    case "2":
      write("Please enter the name of this object.");
      write("The current name is: "+keyMap["~NAME~"] );
      write("Input '**' to indicate no change");
      input_to("redo_names",0,keyMap);
      return;
      break;

    case "3":
    write("Please enter the key words for this item. Separate with commas.(dagger,silver dagger,Dagger,)");
    write("ID's already assigned to the item are:"+implode(keyMap["~ID~"],"\n\t"));
    write("Enter '**' to indicate no change to the ID's");

      input_to("redo_ids",0,keyMap);
      return;
      break;

    case "4":
      write("Please enter the short description, or the description you see in your inventory.");
      write("Use:");
      write(" $C for color");
      write(" $M for Material");
      write(" $T for the base type");
      write(" IE You create a cloak from red silk. You use 'A heavily embroidered flowing $C $M $T'");
      write("    Would result in A heavily embroidered flowing red silk cloak.");
      write(" NOTE: skins don't have a color so no $C is required.");

      input_to("redo_shortDesc",0,keyMap);
      return;
      break;

    case "5":
      write("Please input the Long describe for this Object.");
      write("Enter '~r' to reset the long. '**' completes the");
      write("long description. '~q' will abort changing the long");
      write("and leave it as it was.");
      write("Entering multiple lines is okay.");

      input_to("redo_long",0,keyMap,"");
      return;
      break;

    default:
      write("I don\'t know what you mean to change.");
      final_check(0,keyMap);
      return;
      break;
    }
  }
}

void finish_object(mapping keyMap, string template){

    string name;
    string fileName;
    mixed ret;

    keyMap["~CREATOR~"]=TPQN;

    if (file_size("/d/players/"+TPQN) == -1) {
        mkdir("/d/players/"+TPQN);
    }
    fileName= "/d/players/"+TPQN+"/"+file;
    if (file_exists(fileName+".c")) {
        rm(fileName+".c");
    }
    ret = "/daemon/generator_d"->make_file(template,fileName,keyMap);
    if (stringp(ret)) {
        write("ERROR: "+ret);
        remove();
        return;
    }
    write("You successfully finish "+ret->query_short()+".");
    ret->move(ETP);
    remove();

}
