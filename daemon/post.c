#include <std.h>
#include <daemons.h>
#include <security.h>
#include <post.h>

inherit OBJECT;

private string __Forward;
private mapping __MyGroups;
private mapping *__BoxInfo;
nosave int __Current, __JustSending, __FwdFlag;
nosave private int *__Delete;
nosave private string __Owner;
nosave mapping __MudGroups, __TmpPost;

void create() {
    ::create();
    set_name("post box");
    set_id(({ "box", "post box", POSTAL_ID }) );
    set_short("an imaginary post box");
    set_long("You mail with this.\n");
    __FwdFlag = -1;
    __BoxInfo = ({});
    __MyGroups = ([]);
    __MudGroups = ([]);
    __TmpPost = ([]);
}

void init() {
    int i;

    if(this_player() != environment(this_object())) {
        remove();
        if(this_object()) destruct(this_object());
        return;
    }
    __BoxInfo = ({});
    __MyGroups = ([]);
    __MudGroups = (mapping)LOCALPOST_D->query_mud_groups();

// Prevents any old player from using the general mail groups for
// all users or all wizard.  -- Thorn 950607

    if(!wizardp(TP)) {
        map_delete(__MudGroups, "users");
        map_delete(__MudGroups, "immortals");
    }
////////////////
    __Owner = (string)this_player()->query_name();
    restore_post_box();
    if(!(i=sizeof(__BoxInfo))) {
        __Current = 0;
        return;
    }
    __Current = -1;
    for(i=0; i<sizeof(__BoxInfo) && __Current == -1; i++)
      if(!__BoxInfo[i]["read"]) __Current = i;
    __Delete = allocate(sizeof(__BoxInfo));
}

void start_mail(string str) {
    if(str && str != "") {
        __JustSending = 1;
        do_mail(str);
        return;
    }
    message("mail", "%^GREEN%^Imaginary Intermud Postal Service (IIPS) 2.0"
      "\nDescartes of Borg 1993, 1994 (type \"?\" for help)%^RESET%^", this_player());
    message("mail", "%^BLUE%^%^BOLD%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
      "-=-=-=%^RESET%^", this_player());
    if((int)this_player()->getenv("NO_MAIL_HEADERS")) do_mail(0);
    else headers(0);
}

void do_mail(string str) {
    if(str) get_to(str);
    else {
        message("prompt", POSTAL_PROMPT, this_player());
        input_to("postal_cmd");
    }
}

void postal_cmd(string str) {
    string cmd, arg;
    string *args;
    int x, i;

    if(!str || str == "") {
        for(__Current=-1,i=0,x=sizeof(__BoxInfo); i<x && __Current==-1; i++)
          if(!__BoxInfo[i]["read"]) __Current = i;
        cmd = (__Current+1)+"";
    }
    else cmd = str;
    if(sscanf(cmd, "%d", x)) {
        if(x>0 && x<=sizeof(__BoxInfo)) {
            read_mail(__Current = x-1);
            return;
        }
        else {
            message("mail", "Invalid letter number (\"?\" for help)\n",
              this_player());
            do_mail(0);
            return;
        }
    }
    cmd = (args = explode(str, " "))[0][0..0];
    if(sizeof(args) > 1) arg = implode(args[1..sizeof(args)-1], " ");
    else arg = "";
    switch(cmd) {
        case "a": add_group(arg); break;
        case "x": remove_group(arg); break;
        case "g": do_groups(arg); return;
        case "w": set_forward(arg); break;
        case "?": do_help(arg); return;
        case "s": case "S":
            if(!wizardp(this_player()))
              message("mail", "Save option only for creators.\n",this_player());
            else do_save(cmd, arg);
            break;
        case "R": case "r": do_reply(cmd, arg); return;
        case "F": case "f": do_forward(cmd, arg); return;
        case "Q": case "q": do_quit(cmd); return;
        case "m": get_to(arg); return;
        case "d": case "u": handle___Delete(cmd, arg); break;
        case "h": do_header(arg); return;
        default:
          message("mail", "Invalid postal command (\"?\" for help)\n", this_player());
    }
    do_mail(0);
}

void do_groups(string str) {
    if(!__MyGroups) __MyGroups = ([]);
    if(!str || str == "") {
      message("system", "Personal and "+mud_name()+" groups for the IIPS:", this_player());
      this_player()->more(explode(format_page(keys(__MudGroups)+keys(__MyGroups),
        4), "\n"), "system", (: this_object(), "do_mail" :));
      return;
    }
    if(!__MudGroups[str] && !__MyGroups[str]) {
      message("system", "Group "+str+" does not exist.\n", this_player());
    }
    else if(__MudGroups[str]) {
      write("Members of the "+mud_name()+" IIPS group "+str+":");
      write(format_page(__MudGroups[str], 4));
    }
    else {
      write("Members of your personal IIPS group "+str+":");
      write(format_page(__MyGroups[str], 4));
    }
    do_mail(0);
}

void add_group(string str) {
    string *members;
    string grp, a, b;
    int i;

    if(!str || str == "") {
        write("No group specified.");
        return;
    }
    grp = (members=explode(lower_case(str), " "))[0];
    i = sizeof(members -= ({ grp }));
    if(member_array(grp, members) != -1) {
        write("You cannot define a group as a member of itself.");
        return;
    }
    if(__MudGroups[grp]) {
        write(mud_name()+" has already defined a group called "+grp+".");
        return;
    }
    if(user_exists(grp)) {
        write("A player by the name "+grp+" already exists.");
        return;
    }
    if(!__MyGroups[grp]) __MyGroups[grp] = ({});
    __MyGroups = (mapping)LOCALPOST_D->add_group(__Owner, grp, members);
    write("Group "+grp+" added to.");
}

void set_forward(string str) {
    string a, b;

    if(sscanf(str, "%s@%s", a, b) != 2 && !user_exists(str=lower_case(str))) {
        message("mail", sprintf("User %s does not exist.", capitalize(str)),
          this_player());
        return;
    }
    __Forward = str;
    LOCALPOST_D->set_forward(__Owner, __Forward);
}

void remove_group(string str) {
    string *members;
    string grp;

    if(!str || str == "") {
        write("No group specified.");
        return;
    }
    grp = (members = explode(str, " "))[0];
    if(!__MyGroups[grp]) {
        write("No such group "+grp+".");
        return;
    }
    if(!sizeof((members = members-({grp})))) members = __MyGroups[grp];
    __MyGroups = (mapping)LOCALPOST_D->remove_group(__Owner, grp, members);
    write("Members removed from group "+grp+".");
}

void do_help(string str) {
    if(!str) str = "";
    switch(str) {
        case "r": case "R":
          write("Commands r and R");
          write("Syntax: <r (#) (all)>");
          write("        <R (#) (all)>\n");
          write("Allows you to reply to the author of the "
          "__Current letter or of the letter specified.  If you "
          "specify \"all\" as a parameter, the reply goes to the author "
          "of the letter as well as all people originally addessed.  "
          "The \"R\" command differs from the \"r\" command in that "
          "the \"R\" command includes the original text in your reply.");
          break;
        case "f": case "F":
          write("Commands f and F");
          write("Syntax: <f (#) ([list])\n        <F (#) ([list])\n");
          write("Forwards a copy of the __Current letter or of "
          "the letter specified to the recipient list.  "
          "The \"F\" command allows you to add text.");
          break;
        case "q": case "Q":
          write("Commands q and Q");
          write("Syntax: <q>\n        <Q>\n");
          write("Quits out of the mailer.  The \"Q\" command"
          "quits without making any changes to the mail (nothing "
          "is deleted).  \"q\" deletes letters marked for deletion");
          break;
        case "a":
          write("Command a\nSyntax: <a [group] [list]>\n");
          write("Adds a list of players to an individualized "
          "mailer group.  If no such group exists, one is created.");
          break;
        case "x":
          write("Command x\nSyntax: <x [group] [list]>\n");
          write("Deletes a list of players from your mailer group "
          "of choice.  If no player list is given, the whole "
          "groups is deleted.");
          break;
        case "g":
          write("Command g\nSyntax: <g ([group])>\n");
          write("Lists mud and personal groups for the IIPS mailer.  "
          "If no group is specified, all group names are listed.  Otherwise the "
          "members of the group named are listed.");
          break;
        case "s": case "S":
          write("Commands s and S\nSyntax: <s (#) [filename]>");
            write("        <S (#) [filename]>\n");
          write("Only available to immortals.  Saves the post specified "
          "or the current post to the file filename in the wizards mail save "
          "directory.");
          break;
        case "u":
          write("Command u\nSyntax: <u (#)>\n");
          write("Un__Deletes a letter marked for deletion.");
          break;
        case "d":
          write("Command d\nSyntax: <d (#)>\n");
          write("Marks a letter for deletion upon quitting mail.");
        case "h":
          write("Command h\nSyntax: <h (#)>\n");
          write("Lists the headers for all letters, or letters "
          "beginning at the letter number specified.");
          break;
        case "m":
          write("Command m\nSyntax: <m [list]>\n");
          write("Allows you to create a letter and send it to "
          "the list of players and groups you specify.  You will "
          "be prompted at the end of creating the mail for a list "
          "of players or groups who should get carbon copies.");
          break;
        default:
          this_player()->more(explode(read_file(wizardp(this_player()) ?
            POSTAL_CREATOR_HELP : POSTAL_USER_HELP), "\n"), "help",
            (: this_object(), "do_mail" :));
          return;
    }
    do_mail(0);
}

void do_save(string cmd, string str) {
    string tmp, where;
    int i, x;

    if(!str || !(i=strlen(str))) {
        write("You must specify the name of a file to save to.");
        return;
    }
    if(sscanf(str, "%d %s", x, where) != 2) where = str;
    else {
        i = strlen(where);
        __Current = x-1;
    }
    if(__Current < 0 || __Current >= sizeof(__BoxInfo)) {
        write("Invalid letter number  (\"?\" for help).");
        return;
    }
    if(strsrch(where, "..") != -1) {
        message("mail", "Illegal file name.", this_player());
        return;
    }
    tmp = user_path(__Owner)+where;
    if(file_size(tmp) > -1) x = 1;
    else x = 0;
    seteuid(UID_CRESAVE);
    write_file(tmp, (string)LETTER_D->query_letter(__BoxInfo[__Current]["id"]));
    seteuid(getuid());
    if(!x) write("Letter written to new file: "+tmp+".");
    else write("Letter appended to file: "+str+".");
    if(cmd == "S") __Delete[__Current] = 1;
    return;
}

void do_header(string str) {
    int x;

    if(!str || str == "") headers(0);
    else {
        x = atoi(str);
        if(x > 0 && x<=sizeof(__BoxInfo)) headers(x-1);
        else {
            write("Invalid letter number (\"?\" for help).");
            do_mail(0);
        }
    }
}

void headers(int x) {
    string *lines;
    int i;

    if(!(i=sizeof(__BoxInfo))) {
        write("No letters are currently in your post box.");
        __Current = 0;
        do_mail(0);
        return;
    }
    for(lines = ({}); x<i; x++) {
      lines +=({ "%^BLUE%^%^BOLD%^"+(x+1)+"%^RESET%^ "+
          (__BoxInfo[x]["read"] ? "     " :
          "(new)") +(x==__Current ? ">" :
          (__Delete[x] ? "*" : " "))+
          "%^GREEN%^"+
          arrange_string(capitalize(__BoxInfo[x]["from"]), 16)+" "+
          "%^RESET%^"+
          arrange_string(get_header_time(__BoxInfo[x]["date"]), 17)+
          "%^WHITE%^%^BOLD%^"+
          __BoxInfo[x]["subject"]+"%^RESET%^" });
    }
    this_player()->more(lines, "mail", (: this_object(), "do_mail" :));
}

string get_header_time(mixed x) {
    string a, b, c, d, e, the_ctime;
    int y;

    if(stringp(x) && sscanf(x, "%d", y)) the_ctime = ctime(y);
    else if(stringp(x)) the_ctime = x;
    else the_ctime = ctime(x);
//    if(sscanf(the_ctime, "%s %s  %s %s", a, b, c, d) != 4)
//      sscanf(the_ctime, "%s %s %s %s", a, b, c, d);
   if(sscanf(the_ctime, "%s %s  %s %s %s", a, b, c, d, e) != 5)
      sscanf(the_ctime, "%s %s %s %s %s", a, b, c, d, e);
//    return a+" "+b+" "+c+" "+e;
   return b+" "+c+" "+e;
}

void handle___Delete(string cmd, string arg) {
    if(arg && arg != "") __Current = atoi(arg)-1;
    if(__Current < 0 || __Current >= sizeof(__BoxInfo)) {
        write("Invalid letter number (\"?\" for help).");
        return;
    }
    if(cmd == "u" && !__Delete[__Current]) {
        write("Letter "+(__Current+1)+" is not marked for deletion.");
        return;
    }
    if(cmd == "d" && __Delete[__Current]) {
        write("Letter "+(__Current+1)+" is already marked for deletion.");
        return;
    }
    if(cmd == "u") {
        __Delete[__Current] = 0;
        write("Letter "+(__Current+1)+" is no longer marked for deletion.");
        return;
    }
    __Delete[__Current] = 1;
    write("Letter "+(__Current+1)+" is now marked for deletion.");
    return;
}

void do_quit(string str) {
    if(!this_player()->getenv("MAIL_DELETE_PROMPT") || str == "Q")
        really_quit(str);
    else if(member_array(1, __Delete) == -1) really_quit(str);
    else {
        message("prompt", "Delete all marked letters? (y/n) ", this_player());
        input_to("verify_quit");
    }
}

void verify_quit(string str) {
    if(!str || str == "" || lower_case(str[0..0]) == "y") really_quit("q");
    else if(lower_case(str[0..0]) == "n") {
        write("Files will remain un__Deleted.");
        really_quit("Q");
    }
    else {
        message("prmopt", "Invalid input.\nDelete all marked letters? (y/n) ",
		this_player());
        input_to("verify_quit");
    }
}

void really_quit(string str) {
    int i, x;

    if(str == "Q") {
        write("No letters deleted or marked as read.");
        remove();
        if(this_object()) destruct(this_object());
        return;
    }
    i = sizeof(__BoxInfo);
    while(i--) {
        if(__Delete[i]) {
            x++;
            LOCALPOST_D->remove_post(__Owner, __BoxInfo[i]["id"]);
        }
    }
    LOCALPOST_D->flush_mail();
    message("mail", sprintf("%d letters deleted.", x), this_player());
    remove();
    if(this_object()) destruct(this_object());
}

void get_to(string str) {
    if(!str || str == "") {
        write("No users or groups named.");
        do_mail(0);
        return;
    }
// If a player actually tries to send to a general group
// the mail fails  -- Thorn 950607
    if(str == "users" || str == "immortals") {
        if(!wizardp(TP)) {
            do_mail(0);
            return;
        }
    }
///////////////////
    __TmpPost = ([]);
    __TmpPost["to"] = explode(str, " ");
    __TmpPost["from"] = (string)this_player()->query_name();
    __TmpPost["date"] = time();
    message("prompt", "Subject: ", this_player());
    input_to("get_subject");
}

void get_subject(string str) {
    string tmp_str;
    int i, max;

    if(!str || str == "") str = "[No subject]";
    __TmpPost["subject"] = str;
    message("mail", letter_head(__TmpPost), this_player());
    rm(DIR_TMP+"/"+__TmpPost["from"]+".iips");
    this_player()->edit(DIR_TMP+"/"+__TmpPost["from"]+".iips", "get_text",
      this_object());
}

void abort() {
    if(__JustSending) {
        remove();
        if(this_object()) destruct(this_object());
        return;
    }
    do_mail(0);
}

void get_text() {
    if(__FwdFlag != -1) {
        write_file(DIR_TMP+"/"+__TmpPost["from"]+".iips", "\n-----\n"+
          "Original message sent by "+capitalize(__BoxInfo[__FwdFlag]["from"])+
          " to "+capitalize(__Owner)+" on "+ctime(__BoxInfo[__FwdFlag]["date"])+
          ":\n-----\n"+(string)LETTER_D->query_letter(__BoxInfo[__FwdFlag]["id"]));
        __FwdFlag = -1;
    }
    __TmpPost["message"] = read_file(DIR_TMP+"/"+__TmpPost["from"]+".iips")+"\n";
    if(wizardp(this_player()) && file_exists(user_path(__Owner)+".sig"))
        __TmpPost["message"]+= read_file(user_path(__Owner)+".sig")+"\n";
    rm(DIR_TMP+"/"+__TmpPost["from"]+".iips");
    if(!this_player()->getenv("MAIL_NO_CC")) {
        message("prompt", "Cc: ", this_player());
        input_to("get_cc");
        return;
    }
    get_cc("");
}

void get_cc(string str) {
    string dead;
    string *who, *diff, *orig;

// If a player actually tries to send to a general group
// the cc fails  -- Thorn 950607
    if(strsrch(str, "users") != -1 || strsrch(str, "immortals") != -1) {
        if(!wizardp(TP)) {
            get_cc("");
            return;
        }
    }
///////////////////

    if(!__TmpPost["cc"]) __TmpPost["cc"] = ({});
    if(str && str != "") __TmpPost["cc"] += explode(lower_case(str), " ");
    orig = distinct_array(__TmpPost["to"]+__TmpPost["cc"]);
    diff = orig - (who=(string *)LOCALPOST_D->post_letter(__TmpPost));
    if(sizeof(who))
        write("Mail sent successfully to:\n"+format_page(who, 3));
    else {
        if(wizardp(this_player())) dead = user_path(__Owner)+"dead.letter";
        else dead = DIR_TMP+"/post/"+__Owner+".dead";
        write("No recipients found.  Appending to "+dead+".");
        write_file(dead, __TmpPost["message"]+"\n");
    }
    if(__JustSending) {
        remove();
        if(this_object()) destruct(this_object());
        return;
    }
    do_mail(0);
}

void do_reply(string cmd, string arg) {
    string *tmp;
    string recep;
    int x, i;

    if(arg && arg != "") {
        if(sscanf(arg, "%d %s", x, recep) != 2) {
            if(!sscanf(arg, "%d", x)) recep = arg;
            else {
                recep = "";
                __Current = x-1;
            }
        }
        else __Current = x-1;
    }
    else recep = "";
    if(__Current < 0 || __Current >= sizeof(__BoxInfo)) {
        write("Invalid letter number (\"?\" for help).");
        do_mail(0);
        return;
    }
    else if(recep != "" && recep != "all" && recep != "to") {
        write("Invalid reply parameter: "+recep+" (\"?\" for help).");
        do_mail(0);
        return;
    }
    __TmpPost["from"] = (string)this_player()->query_name();
    if(recep == "") {
        __TmpPost["to"] = ({ __BoxInfo[__Current]["from"] });
        __TmpPost["cc"] = ({});
    }
    else if(recep == "to") {
        __TmpPost["to"] = ({__BoxInfo[__Current]["from"] })+__BoxInfo[__Current]["to"];
        __TmpPost["cc"] = ({});
    }
    else {
        __TmpPost["to"] = ({__BoxInfo[__Current]["from"] })+__BoxInfo[__Current]["to"];
        __TmpPost["cc"] = __BoxInfo[__Current]["cc"];
    }
    __TmpPost["date"] = time();
    if(strlen(__BoxInfo[__Current]["subject"]) < 4 ||
      __BoxInfo[__Current]["subject"][0..3] != "RE: ")
        __TmpPost["subject"] = "RE: "+__BoxInfo[__Current]["subject"];
    else __TmpPost["subject"] = __BoxInfo[__Current]["subject"];
    message("mail", letter_head(__TmpPost), this_player());
    rm(DIR_TMP+"/"+__TmpPost["from"]+".iips");
    if(cmd == "R") {
        tmp = explode((string)LETTER_D->query_letter(__BoxInfo[__Current]["id"]),
          "\n");
        __TmpPost["message"] = "On "+ctime(__BoxInfo[__Current]["date"])+", "+
          capitalize(__BoxInfo[__Current]["from"])+" wrote:\n>"+
          implode(tmp, "\n> ");
        write_file(DIR_TMP+"/"+__TmpPost["from"]+".iips", __TmpPost["message"]);
    }
    this_player()->edit(DIR_TMP+"/"+__TmpPost["from"]+".iips", "get_text",
        this_object());
}

void do_forward(string cmd, string arg) {
    string recep;
    int x, i;

    if(!arg || arg == "") {
        write("Recepient for forward missing (\"?\" for help).");
        do_mail(0);
        return;
    }
    if(sscanf(arg, "%d %s", x, recep) == 2) {
        __Current = x-1;
        __TmpPost["to"] = explode(lower_case(recep), " ");
    }
    else __TmpPost["to"] = explode(lower_case(arg), " ");
    if(__Current < 0 || __Current >= sizeof(__BoxInfo)) {
        write("Invalid letter number (\"?\" for help).");
        do_mail(0);
        return;
    }
    __TmpPost["from"] = (string)this_player()->query_name();
    __TmpPost["date"] = time();
    if(strlen(__BoxInfo[__Current]["subject"]) < 10 ||
      __BoxInfo[__Current]["subject"][0..9] != "(forward) ")
        __TmpPost["subject"] = "(forward) "+__BoxInfo[__Current]["subject"];
    else __TmpPost["subject"] = __BoxInfo[__Current]["subject"];
    __TmpPost["cc"] = ({});
    message("mail", letter_head(__TmpPost), this_player());
    rm(DIR_TMP+"/"+__TmpPost["from"]+".iips");
    if(cmd == "F") {
        __FwdFlag = __Current;
        this_player()->edit(DIR_TMP+"/"+__TmpPost["from"]+".iips", "get_text",
          this_object());
    }
    else {
        write_file(DIR_TMP+"/"+__TmpPost["from"]+".iips",
          "\n-----\nOriginal letter sent by "+capitalize(__BoxInfo[__Current]["from"])+" to "+capitalize(__Owner)+" "+ctime(__BoxInfo[__Current]["date"])+":\n"+
          "-----\n");
        write_file(DIR_TMP+"/"+__TmpPost["from"]+".iips",
          (string)LETTER_D->query_letter(__BoxInfo[__Current]["id"]));
        get_text();
    }
}

void read_mail(int x) {
    string borg;

    borg = "Letter "+(x+1)+(__Delete[x] ? "[DELETED]:\n" : ":\n");
    borg += letter_head(__BoxInfo[x]);
    borg += "\n"+(string)LETTER_D->query_letter(__BoxInfo[x]["id"])+"\n";
    LOCALPOST_D->mark_read(__Owner, __BoxInfo[x]["id"]);
    __BoxInfo[x]["read"] = 1;
    this_player()->more(explode(borg, "\n"), "mail",(:this_object(),"do_mail":));
}

string letter_head(mapping this_letter) {
    int i, max;
    string ret, tmp;

    if(stringp(this_letter["date"]) && sscanf(this_letter["date"],"%d",i))
      tmp = ctime(i);
    else if(!stringp(this_letter["date"]))
      tmp = ctime(this_letter["date"]);
    else tmp = this_letter["date"];
    ret = sprintf("%s from ", tmp);
    ret += "%^GREEN%^"+capitalize(this_letter["from"])+"%^RESET%^\n";
    ret += "To: ";
    for(i=0, max = sizeof(this_letter["to"]); i<max; i++)
      ret += capitalize(this_letter["to"][i])+" ";
    if(!sizeof(this_letter["cc"])) ret = wrap(ret);
    else {
        ret = wrap(ret)+"Cc: ";
        for(i=0, max = sizeof(this_letter["cc"]); i<max; i++)
          ret += capitalize(this_letter["cc"][i])+" ";
        ret = wrap(ret);
    }
    ret += "Subject: %^GREEN%^"+this_letter["subject"]+"%^RESET%^\n";
    return ret;
}

int valid_shadow() { return 1; }

int drop () { return 1; }

int get() { return 0; }

protected void restore_post_box() {
    mapping borg;

    borg = (mapping)LOCALPOST_D->query_post_data(__Owner);
    __BoxInfo = borg["box info"];
    __MyGroups = borg["my groups"];
    __Forward = borg["forward"];
}

protected void save_post_box() {
    LOCALPOST_D->remake_post_box(__Owner, ([ "box info" : __BoxInfo,
      "forward" : __Forward, "my groups" : __MyGroups ]));
}
