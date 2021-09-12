//      /adm/daemon/bboard_d.c
//      from the Nightmare mudlib
//      a daemon to service the new Neightmare bboard
//      created by Descartes of Borg 6 march 1993

#include <std.h>
#include <dirs.h>
#include <security.h>
#include <bboard.h>
#include <daemons.h>

inherit DAEMON;

mapping *posts;
mixed *read_by;
nosave string *edit_ok;
nosave string current;

int valid_edit(int x, string id);
string when(int x);
mixed *sub_array(mixed *arr, int x);
int direct_post(string id, string poster, string title, string msg);

void create() {
    ::create();
    current = 0;
    edit_ok = ({});
    posts = ({});
    read_by = ({});
}

int remove_message(string id, int number) {
    if(!id || number < 0)
        return BAD_DATA;
    if(current != id)
    {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0) return INVALID_MSG;
        current = id;
        restore_object(DIR_BOARDS+"/"+current);
    }
    edit_ok = previous_object()->query_edit_ok();
    if(!this_player())
        return ILLEGAL_ACCESS;
    if(!sizeof(posts))
        return INVALID_MSG;
    if(number > sizeof(posts)-1 || number < 0)
        return INVALID_MSG;
    if(!valid_edit(number, geteuid(this_player())))
        return ILLEGAL_ACCESS;
    posts -= ({ posts[number] });
    read_by = sub_array(read_by, number);
    save_object(DIR_BOARDS+"/"+current);
    return BBOARD_OK;
}

int edit_note(string id, int number) {
    string *lines;
    string file;
    int i;

    if(!id || number < 0) return BAD_DATA;
    if(current != id) {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0) return INVALID_MSG;
        current = id;
        edit_ok = ({});
        restore_object(DIR_BOARDS+"/"+current);
    }
    if(!this_player()) return ILLEGAL_ACCESS;
    if(!sizeof(posts)) return INVALID_MSG;
    if(number > sizeof(posts)-1 || number < 0) return INVALID_MSG;
    if(!valid_edit(number, geteuid(this_player())))
        return ILLEGAL_ACCESS;
    lines = explode(posts[number]["message"], "\n");
    file = BBOARD_EDIT+posts[number]["owner"];
    rm(file);
    for(i=0; i<sizeof(lines); i++) write_file(file, lines[i]+"\n");
    posts -= ({ posts[number] });
    read_by = sub_array(read_by, number);
    return BBOARD_OK;
}

int post_message(string id, string title) {
    string body;

    if(!id || !title) return BAD_DATA;
    if(id != current) {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0) {
            posts = ({});
            read_by = ({});
            current = id;
        }
        else {
            current = id;
            restore_object(DIR_BOARDS+"/"+current);
        }
    }
    body = read_file(BBOARD_EDIT+(string)this_player()->query_name());
    rm(BBOARD_EDIT+(string)this_player()->query_name());
    if(!body) {
        save_object(DIR_BOARDS+"/"+current);
        return EDIT_ABORT;
    }
    if(avatarp(TP) && TP->query_disguised()){

       posts += ({ ([
          "owner": (string)this_player()->query_vis_name(),
          "date": time(),
          "size": strlen(body),
          "title": title,
          "level": (int)this_player()->query_level(),
          "message": body,
       ]) });
    } else {

      posts += ({ ([
         "owner": (string)this_player()->query_name(),
         "date": time(),
              "size": strlen(body),
         "title": title,
         "level": (int)this_player()->query_level(),
         "message": body,
      ]) });
    }

     read_by += ({ ({ (string)this_player()->query_name() }) });
    save_object(DIR_BOARDS+"/"+current);
    //taking this out for now to see if it is crashing the bot
    //IPC->ipc_send_all("CHAT:" + id + ":" + " " + ":" + this_player()->query_name() + ":" + strip_colors(body) + "\n");
    return BBOARD_OK;
}

int post_message_ingame(string id, string title, string body) {

    if(!id || !title || !body) return BAD_DATA;
    if(id != current) {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0) {
            posts = ({});
            read_by = ({});
            current = id;
        }
        else {
            current = id;
            restore_object(DIR_BOARDS+"/"+current);
        }
    }
    if(avatarp(TP) && TP->query_disguised()){

       posts += ({ ([
          "owner": (string)this_player()->query_vis_name(),
          "date": time(),
          "size": strlen(body),
          "title": title,
          "level": (int)this_player()->query_level(),
          "message": body,
       ]) });
    } else {

      posts += ({ ([
         "owner": (string)this_player()->query_name(),
         "date": time(),
              "size": strlen(body),
         "title": title,
         "level": (int)this_player()->query_level(),
         "message": body,
      ]) });
    }

     read_by += ({ ({ (string)this_player()->query_name() }) });
    save_object(DIR_BOARDS+"/"+current);
    return BBOARD_OK;
}

mapping get_message(string id, int number)
{
    if (!id || number < 0) {
        return 0;
    }
    if (current != id) {
        if (file_size(DIR_BOARDS + "/" + id + ".o") < 0) {
            return 0;
        }
        current = id;
        restore_object(DIR_BOARDS + "/" + current);
    }
    if (!sizeof(posts) || sizeof(posts) - 1 < number) {
        return 0;
    }
    return posts[number];
}

int dump_board(string id, string fname)
{
    mapping message;
    string tosave;
    int saved = 0;

    if (!id) {
        return 0;
    }
    if (current != id) {
        if (file_size(DIR_BOARDS + "/" + id + ".o") < 0) {
            return 0;
        }
        current = id;
        restore_object(DIR_BOARDS + "/" + current);
    }

    if (!sizeof(posts)) {
        return 0;
    }

    foreach(message in posts)
    {
        tosave = "";
        tosave += "From: " + message["owner"] + "\n";
        tosave += "Date: " + ctime(message["date"]) + "\n";
        tosave += "Subject: " + message["title"] + "\n\n";
        tosave += message["message"];

        write_file(fname + "." + message["date"] + ".txt", tosave, 1);
        saved++;
    }
    return saved;
}

void save_message(string id, int number, string fname)
{
    mapping message;
    string tosave;

    message = get_message(id, number);

    if (!mapp(message)) {
        return 0;
    }
    tosave = "";
    tosave += "From: " + message["owner"] + "\n";
    tosave += "Date: " + ctime(message["date"]) + "\n";
    tosave += "Subject: " + message["title"] + "\n\n";
    tosave += message["message"];

    write_file(fname + "." + message["date"] + ".txt", tosave, 1);
}

mapping *query_posts(string id)
{
    int i;

    if(!id) return 0;
    if(current != id)
    {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0)
            return ([]);
        current = id;
        restore_object(DIR_BOARDS+"/"+current);
    }
    return posts;
}

mixed *query_read_by(string id)
{
    if(!id) return 0;
    if(current != id)
    {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0)
            return ({});
        current = id;
        restore_object(DIR_BOARDS+"/"+current);
    }
    return read_by;
}

/**
 * Formats bboard post for display in the list
 */
string format_board_message(mapping post,int index,int readby)
{
    string str;
    int itime;
    int scrwidth = atoi(TP->getenv("SCREEN"));
    scrwidth = scrwidth?scrwidth:75;
    str = "";
    str +=((readby==-1?"%^WHITE%^{":"%^GREEN%^[")+"%^BOLD%^"+(index+1>9 ?(index+1): " "+(index+1))+"%^RESET%^"+(readby==-1?"%^WHITE%^}":"%^GREEN%^]"));
    itime = post["date"];
    if((PO->query_ooc_board()&&!PO->query_anonymous_board())||wizardp(TP))
        str += "%^BOLD%^%^GREEN%^"+arrange_string(capitalize(post["owner"]),10)+"%^RESET%^%^BLUE%^|";
    str += "%^ORANGE%^"+arrange_string(post["title"],scrwidth-42) +"%^RESET%^%^BLUE%^|%^RESET%^%^GREEN%^";
    if(PO->query_ooc_board())
        str += (when(itime)+"\n");
    else
        str +=sprintf("%2d",hour(itime))+":"+(minutes(itime) > 9?minutes(itime):"0"+minutes(itime))+" "+
            sprintf("%2d",(date(itime)))+" "+
            arrange_string(month(itime),12)+" "+
            year(itime)+"\n";
    return str;
}

string display_board(string id) {
    string borg;
    int i, itime;

    if(!id) return 0;
    if(current != id) {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0) {
            borg = ("No messages posted.\n");
            return borg;
        }
        current = id;
        restore_object(DIR_BOARDS+"/"+current);
    }
    if(sizeof(posts) < 1) {
        borg = ("No messages posted.\n");
        return borg;
    }
    borg = "";
    for(i=0; i<sizeof(posts); i++)
    {
        borg+=format_board_message(posts[i],i,member_array( (string)this_player()->query_name(), read_by[i]));
    }
    return borg;
}

string display_board_top(string id) {
    string borg;
    int i,showposts,itime;

    if(!id) return 0;
    if(current != id)
    {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0)
        {
            borg = ("No messages posted.\n");
            return borg;
        }
        current = id;
        restore_object(DIR_BOARDS+"/"+current);
    }
    if(sizeof(posts) < 1)
    {
        borg = ("No messages posted.\n");
        return borg;
    }
	i = sizeof(posts);
	if (i < 20)
        showposts = 0;
	else
        showposts = i - 20;
    borg = "";
    for(i=(sizeof(posts)-1);i>=showposts;i--) {
        borg+=format_board_message(posts[i],i,member_array( (string)this_player()->query_name(), read_by[i]));
    }
    return borg;
}

int valid_edit(int x, string id) {
    string who;
    int level;

    who = posts[x]["owner"];
    level = posts[x]["level"];
    if(id == UID_ROOT) return 1;
/*  Root may remove any notes */
    if(id == who) return 1;
/* Arches may remove any notes */
    if(TP) if(archp(TP)) return 1;
/* You cannot remove an arch's note unless you are an arch */
    if(member_group(who, "superuser")) return 0;
    if(member_group(who, "assist")) return 0;
    if (objectp(TP) && wizardp(TP)) {
        if (TP->query_highest_level() >= level)
            return 1;
        else
            return 0;
    }
// If you are an Avatar, you can remove player and System messages.
    if(TP) if(avatarp(TP) && level < 250) return 1;
/* Allow the board to have special priveledges */
    if(member_array(id, edit_ok) != -1) return 1;

// Default is to deny access.
    return 0;
}

string when(int x) {
    string date, day, mon, year, hour, min, sec;

    if(sscanf(ctime(x), "%s %s  %s %s %s", day, mon, date, hour, year) !=5)
        sscanf(ctime(x), "%s %s %s %s %s", day, mon, date, hour, year);
    sscanf(hour, "%s:%s:%*s", hour, min, sec);
    return(hour+":"+min+" "+mon+" "+arrange_string(date,2)+" "+year);
}

string get_title(string id, int number) {
    if(!id || number < 0) return 0;
    if(current != id) {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0) return 0;
        current = id;
        restore_object(DIR_BOARDS+"/"+current);
    }
    if(number > sizeof(posts)-1) return 0;
    return posts[number]["title"];
}

mixed *sub_array(mixed *arr, int x) {
    mixed *a;
    int i;

    for(i=0, a = ({}); i< x; i++) a += ({ arr[i] });
    for(i=x+1; i<sizeof(arr); i++) a+= ({ arr[i] });
    return a;
}

int set_read(string id, string who, int number) {
    string a;

    if(!id || !who || number < 0) return 0;
    if(sscanf(id, "%*s..%s", a) ==1) return 0;
    if(current != id) {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0) return 0;
        current = id;
        restore_object(DIR_BOARDS+"/"+current);
    }
    if(number > sizeof(read_by)-1) return 0;
    if(member_array(who, read_by[number]) != -1) return 1;
    read_by[number] += ({ who });
    save_object(DIR_BOARDS+"/"+current);
    return 1;
}

int get_num_posts(string id) {
    if(!id) return 0;
    if(current != id) {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0) return 0;
        current = id;
        restore_object(DIR_BOARDS+"/"+current);
    }
    return sizeof(posts);
}

int get_new_post(string id, string who) {
    int i;

    if(!id || !who) return -1;
    if(current != id) {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0) return -1;
        current = id;
        restore_object(DIR_BOARDS+"/"+current);
    }
    for(i=0; i<sizeof(read_by); i++)
        if(member_array(who, read_by[i]) == -1) break;
    return i;
}

void clean_up() { return; }

// Direct posting interface - thorn 001212
int direct_post(string id, string poster, string title, string msg) {
    string body;

    if(!id || !title) return BAD_DATA;
    if(id != current) {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0) {
            posts = ({});
            read_by = ({});
            current = id;
        }
        else {
            current = id;
            restore_object(DIR_BOARDS+"/"+current);
        }
    }
    body = msg;
    posts += ({ ([
       "owner": poster,
       "date": time(),
       "size": strlen(body),
       "title": title,
       "level": -1,
       "message": body,
    ]) });
    read_by += ({ ({ }) });

    save_object(DIR_BOARDS+"/"+current);
    return BBOARD_OK;
}

int purge_read(string id) {
    string a;
    int loop;

    if(!id ) return 0;
    if(sscanf(id, "%*s..%s", a) ==1) return 0;
    if(current != id) {
        if(file_size(DIR_BOARDS+"/"+id+".o") < 0) return 0;
        current = id;
        restore_object(DIR_BOARDS+"/"+current);
    }
    if(!sizeof(read_by)) return 0;
    while (loop < sizeof(read_by)) {
        read_by[loop] = filter_array(read_by[loop],"_does_user_exist","/daemon/filters_d");
        loop++;
    }
    save_object(DIR_BOARDS+"/"+current);
    return 1;
}
