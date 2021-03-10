#include <post.h>
#include <objects.h>
#include <security.h>

private string __Letter;
private string *__Undeleted;
nosave private int __LetterPtr, __PostalPtr;
nosave private string *__LettersDir, *__PostalDir;

void create()
{
    string tmp;
    int i, y;

    seteuid(UID_POSTALSAVE);
    __Letter = "";
    __Undeleted = ({});
    __LettersDir = ({});
    __PostalDir = ({});
    __LetterPtr = 0;
    __PostalPtr = 0;
    y = 0;
    for(i=0; i<10; i++) {
        if(file_size(DIR_LETTERS+"/"+i) == -2)
            y += sizeof(get_dir(DIR_LETTERS+"/"+i+"/"));
            //quit adding to the array - Saide, September 2016
            //not sure what this will do? If anything.
            if(y > 9999) break;
          __LettersDir += get_dir(DIR_LETTERS+"/"+i+"/");
      }
    i = sizeof(tmp = get_dir(DIR_POSTAL+"/"));
    while(i--) {
        if(file_size(DIR_POSTAL+"/"+tmp[i]) == -2)
          __PostalDir += get_dir(DIR_POSTAL+"/"+tmp[i]+"/");
      }
    seteuid(getuid());
    manage_letters();
    call_out("manage_postal", 60);
  }

protected int valid_access(object ob) {
    if(base_name(previous_object()) == OB_POSTAL) return 1;
    return (geteuid(ob) == UID_POSTAL || geteuid(ob) == UID_ROOT);
  }

string create_letter(string str, string *who) {
    int tmp;
    string id, dir;

    if(!valid_access(previous_object())) return 0;
    id = sprintf("%d", tmp = time());
    dir = DIR_LETTERS+"/"+(tmp%10);
    seteuid(UID_POSTALSAVE);
    if(file_size(dir+"/") != -2) {
        mkdir(dir);
        seteuid(getuid());
    }
    while(file_size(dir+"/"+id+".o") != -1) id = sprintf("%d", tmp += 10);
    seteuid(getuid());
    __Letter = str;
    __Undeleted = who;
    save_letter(dir+"/"+id);
    return id;
}

void reassign_letter(string id, mapping forwards) {
    string *old;
    int i, x;

    if(!valid_access(previous_object()) || !restore_letter(id)) return;
    i = sizeof(old = keys(forwards));
    while(i--) {
        if((x=member_array(old[i], __Undeleted)) < 0) continue;
        __Undeleted[x] = forwards[old[i]];
    }
    save_letter(DIR_LETTERS+"/"+id[strlen(id)-1..strlen(id)-1]+"/"+id);
}

protected void save_letter(string str) {
    seteuid(UID_POSTALSAVE);
    save_object(str);
    seteuid(getuid());
  }

protected int restore_letter(string id) {
    string dir;
    int x;

    x = strlen(id) - 1;
    dir = DIR_LETTERS+"/"+id[x..x];
    seteuid(UID_POSTALSAVE);
    if(file_size(dir+"/"+id+".o") < 0) return 0;
    restore_object(dir+"/"+id);
    seteuid(getuid());
    return 1;
  }

string query_letter(string id) {
    if(!valid_access(previous_object())) return "Illegal access.\n";
    if(!restore_letter(id)) return "Invalid message.\n";
    return __Letter;
  }

void delete_letter(string id, string who) {
    string *tmp;
    int i;

    if(!valid_access(previous_object())) return;
    if(!restore_letter(id)) return;
    __Undeleted -= ({ who });
    i = sizeof(tmp = __Undeleted);
    seteuid(UID_POSTALSAVE);
    while(i--) {
        if(!user_exists(tmp[i])) {
            __Undeleted -= ({ tmp[i] });
            seteuid(UID_POSTALSAVE);
            rm(DIR_POSTAL+"/"+tmp[i][0..0]+"/"+tmp[i]+".o");
            seteuid(getuid());
	  }
        else if(!file_exists(DIR_POSTAL+"/"+tmp[i][0..0]+"/"+tmp[i]+".o"))
          __Undeleted -= ({ tmp[i] });
      }
    if(!sizeof(__Undeleted))
      rm(DIR_LETTERS+"/"+id[strlen(id)-1..strlen(id)-1]+"/"+id+".o");
    else save_letter(DIR_LETTERS+"/"+id[strlen(id)-1..strlen(id)-1]+"/"+id);
    seteuid(getuid());
}

protected void manage_letters() {
    string str, ext;
    string *tmp;
    int x, i;

    if(!pointerp(__LettersDir) || !sizeof(__LettersDir)) return;
    if(__LetterPtr >= sizeof(__LettersDir)) __LetterPtr = 0;
    sscanf(__LettersDir[__LetterPtr], "%s\.%s", str, ext);
    __LetterPtr++;
    if(!restore_letter(str)) {
        call_out("manage_letters", 120);
        return;
      }
    i = sizeof(tmp = __Undeleted);
    seteuid(UID_POSTALSAVE);
    while(i--) {
        if(!user_exists(tmp[i])) {
            __Undeleted -= ({ tmp[i] });
            seteuid(UID_POSTALSAVE);
            rm(DIR_POSTAL+"/"+tmp[i][0..0]+"/"+tmp[i]+".o");
            seteuid(getuid());
        }
        else if(!file_exists(DIR_POSTAL+"/"+tmp[i][0..0]+"/"+tmp[i]+".o"))
          __Undeleted -= ({ tmp[i] });
    }
    if(!sizeof(__Undeleted)) {
        rm(DIR_LETTERS+"/"+str[strlen(str)-1..strlen(str)-1]+"/"+str+".o");
        seteuid(getuid());
    }
    else save_letter(DIR_LETTERS+"/"+str[strlen(str)-1..strlen(str)-1]+"/"+str);
    call_out("manage_letters", 120);
}

protected void manage_postal() {
    string pl, ext;

    if(!pointerp(__PostalDir) || !sizeof(__PostalDir)) return;
    if(__PostalPtr >= sizeof(__PostalDir)) __PostalPtr = 0;
    sscanf(__PostalDir[__PostalPtr], "%s\.%s", pl, ext);
    seteuid(UID_POSTALSAVE);
    if(!file_exists(DIR_POSTAL+"/"+pl[0..0]+"/"+pl+".o")) {
        call_out("manage_postal", 120);
        seteuid(getuid());
        return;
      }
    if(!user_exists(pl)) rm(DIR_POSTAL+"/"+pl[0..0]+"/"+pl+".o");
    seteuid(getuid());
    call_out("manage_postal", 120);
    __PostalPtr++;
   }
