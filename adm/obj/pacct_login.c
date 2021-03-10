// /adm/obj/paccount.c
// Shadowgate Player Accounting
// Base code (loosely):
// /adm/obj/login.c

#include <config.h>
#include <news.h>
#include <flags.h>
#include <security.h>
#include <daemons.h>
#include <objects.h>
#include <ansi.h>
nosave private int __CrackCount;
nosave private string __Name;
nosave private string __Email;
nosave private object __Player, __Pacct;
nosave private string subname, xyz, __ob_name;
nosave private int flag = 0;

void create() {
    seteuid(UID_ROOT);
    __Name = "";
    __Email = "";
    __CrackCount = 0;
    __Player = 0;
    __Pacct = 0;
}

void logon() {
    int Z, ttl;
    call_out("idle", LOGON_TIMEOUT);
   if(catch(__Pacct = new(OB_PACCT))) {
      message("logon", "Someone appears to be messing with the accounts object.\n"
              "Please try again in a few minutes.\n", this_object());
      internal_remove();
      return;
   }
    Z = random(3)+1;
    message("logon", read_file(WELCOME+Z),this_object());
    message("logon", sprintf("\n        Driver: %s        Mudlib: %s %s\n",
        version(), mudlib(), mudlib_version()), this_object());
    ttl = "/adm/daemon/shutdown_d.c"->query_time_left();
    if(ttl > 0) {
        message("logon", "\n        <<< The MUD will be rebooting shortly.  Reboot in "+ttl/60+" minute(s)! >>>\n", this_object());
    }

    message("logon", "\nWhat is your email address? ", this_object());
    input_to("get_email");
}

protected void get_email(string str) {
  string user,host;

  if (stringp(str) && (strlen(str) <= 6)) {
    write("Sorry, I don't believe you.\nAt least TRY to make it valid!\n");
    write("Please enter a valid email address, i.e. username@host.com.\n");
    write("Entering a blatantly invalid email address will result in \n");
    write("immediate removal.\n");
    input_to("get_email");
    return;
  }

  if( sscanf(str,"%s@%s",user,host) != 2) {
    write("Email address must be in the form user@host.\nPlease input again.");
    input_to("get_email");
    return;
    }

    __Email = lower_case(str);
    if ("/adm/obj/master.c"->is_locked()) {
        message("logon", read_file(LOCKED_NEWS), this_object());
        if (locked_access())
            message("logon", "\n    >>> Access allowed <<<\n", this_object());
        else {
            message("logon", "\n    >>> Access denied <<<\n", this_object());
            internal_remove();
            return;
        }
    }
    if (sscanf(__Email, "%s&%s", subname, xyz) == 2) {
        message("logon", "Login name adjusted to "+subname+"\n", this_object());
        __Email = subname;
        __ob_name = "/std/"+xyz+".c";
        if (!file_exists(__ob_name)) {
            message("logon", "Not a valid login. (invalid user file)\n", this_object());
            internal_remove();
            return;
        }
        flag = 1;
    }
    /* can't use this old format anymore.
       if (sscanf(__Name, "%s@%s", subname, xyz) == 2) {
       message("logon", "Login name adjusted to "+subname+"\n", this_object());
       __Name = subname;
       __ob_name = "/std/"+xyz+".c";
       if (!file_exists(__ob_name)) {
       message("logon", "Not a valid login. (invalid user file)\n", this_object());
       internal_remove();
       return;
       }
       flag = 1;
       }
    */
    if (flag) {
      destruct(__Player);
      if(catch(__Player = new(__ob_name))){
	message("logon", "The file "+__ob_name+" is not available.\n", this_object());
	internal_remove();
	return;
      }
    }
    if (!file_exists("/adm/save/pacct/"+__Email+".o")) {
      if (file_exists("/adm/save/pacct/arrest/"+__Name+".o")) {
	message("logon","This account has been arrested, you need to see a law member.\n",this_object());
            internal_remove();
        }
      /*****
        if (!((int)BANISH_D->valid_name(__Name))) {
            message("logon", sprintf("\n%s is not a valid name choice for %s.\n",
                    capitalize(__Name), mud_name()), this_object());
            message("logon", sprintf("Names must be alphabetic characters no "
                    "longer than %d letters,\nand no less than %d letters.\n",
                    MAX_USER_NAME_LENGTH, MIN_USER_NAME_LENGTH), this_object());
            message("logon", "\nPlease enter another name: ", this_object());
            input_to("get_name");
            return;
        }
      *****/
        if (!((int)BANISH_D->allow_logon(__Email, query_ip_number()))) {
            message("logon",read_file("/news/register"), this_object());
            internal_remove();
            return;
        }
	/****        if (!MULTI_D->is_allowed(__Name)) {
            message("logon", sprintf("\nThat character name can not be used at this time. \nPlease try again later."), this_object());
            internal_remove();
        }
        ****/
        if (find_player(__Email) && interactive(find_player(__Email))) {
            message("logon", sprintf("That account is already being created.  Please try again later."), this_object());
            internal_remove();
        }
        /******
        message("logon", read_file("/news/newname"), this_object());
        message("logon", sprintf("Do you really wish %s to be your name? (y/n) ",
                capitalize(__Name)), this_object());
        input_to("new_user");
        return;
	*******/
	message("logon", read_file("/news/newpacct"), this_object());
        message("logon", sprintf("Is this [%s] your correct email address? (y/n) ",
                lower_case(__Email)), this_object());
        input_to("new_pacct");
        return;
    }
    if (!((int)BANISH_D->allow_logon(__Email, query_ip_number()))) {
        message("logon", read_file("/news/register"), this_object());
        internal_remove();
        return;
    }
    /****
    if (!MULTI_D->is_allowed(__Name)) {
        message("logon", sprintf("\nThat character name can not be used at this time. \nPlease try again later."), this_object());
        internal_remove();
    }
    ****/
    message("logon", "Password: ", this_object());
    input_to("get__pacct_password", I_NOECHO | I_NOESC);
}

protected void get_pacct_password(string str) {
    if (!str || str == "") {
        message("logon", "\nYou must enter a password.  Try again later.\n",
                this_object());
        internal_remove();
        return;
    }
    if (!check_password(str)) {
        message("logon", "\nInvalid password.\n", this_object());
        log_file("watch/bad_password",sprintf("%s at %s from %s\n",__Email,ctime(time()),query_ip_number()));
        if (++__CrackCount > MAX_PASSWORD_TRIES) {
            message("logon", "No more attempts allowed.\n", this_object());
            internal_remove();
            return;
        }
//        seteuid(UID_LOG);
//        log_file("watch/logon", sprintf("%s from %s at %s\n",__Name,query_ip_number(),ctime(time())));
//        seteuid(getuid());
        destruct(__Player);
        if (!flag)
            __Player = new(OB_USER);
        else {
         if(catch(__Player = new(__ob_name))){
            message("logon", "The file "+__ob_name+" is not available.", this_object());
            internal_remove();
            return;
         }
        }
        message("logon", "Password: ", this_object());
        input_to("get_pacct_password", I_NOECHO | I_NOESC);
        return;
    }
        seteuid(UID_LOG);
        log_file("watch/logon", sprintf("%s from %s at %s\n",__Email,query_ip_number(),ctime(time())));
        seteuid(getuid());
    if (!is_copy()) exec_user();
}
protected void get_user_password(string str) {
    if (!str || str == "") {
        message("logon", "\nYou must enter a password.  Try again later.\n",
                this_object());
        internal_remove();
        return;
    }
    if (!check_password(str)) {
        message("logon", "\nInvalid password.\n", this_object());
        log_file("watch/bad_password",sprintf("%s at %s from %s\n",__Name,ctime(time()),query_ip_number()));
        if (++__CrackCount > MAX_PASSWORD_TRIES) {
            message("logon", "No more attempts allowed.\n", this_object());
            internal_remove();
            return;
        }
//        seteuid(UID_LOG);
//        log_file("watch/logon", sprintf("%s from %s at %s\n",__Name,query_ip_number(),ctime(time())));
//        seteuid(getuid());
        destruct(__Player);
        if (!flag)
            __Player = new(OB_USER);
        else {
         if(catch(__Player = new(__ob_name))){
            message("logon", "The file "+__ob_name+" is not available.", this_object());
            internal_remove();
            return;
         }
        }
        message("logon", "Password: ", this_object());
        input_to("get_password", I_NOECHO | I_NOESC);
        return;
    }
    if(__Player->get_perma_death() > 0 && __Player->get_perma_death() > time()) {

        message("logon", "That character is under permadeath lock out until "+ctime(__Player->get_perma_death())+".", this_object());
        internal_remove();
        return;
    }
        seteuid(UID_LOG);
        log_file("watch/logon", sprintf("%s from %s at %s\n",__Name,query_ip_number(),ctime(time())));
        seteuid(getuid());
    if (!is_copy()) exec_user();
}

protected int locked_access() {
    int i;
    string fore, aft;

    i = sizeof(LOCKED_ACCESS_ALLOWED);
    while (i--) if (member_group(__Name, LOCKED_ACCESS_ALLOWED[i])) return 1;

    //    if (sscanf(__Email, "%s@%s", fore, aft) == 2)
    //    if ((int)BANISH_D->is_guest(__Email))
    //        return 1;

    if ((int)BANISH_D->is_guest(__Email)) return 1;

    //    i = sizeof(LOCKED_ACCESS_ALLOWED);
    //    while (i--) if (member_group(__Name, LOCKED_ACCESS_ALLOWED[i])) return 1;
    return 0;
}

protected int check_password(string str) {
    string pass;

    master()->load_player_from_file(__Name, __Player);
    if ((pass = (string)__Pacct->query_password()) != crypt(str, pass)) return 0;
    return valid_site(query_ip_number());
}

protected int valid_site(string ip) {
    string a, b;
    string *miens;
    int i;

    if (!(i = sizeof(miens = (string *)__Player->query_valid_sites()))) return 1;
    while (i--) {
        if (ip == miens[i]) return 1;
        if (sscanf(miens[i], "%s.*s", a) && sscanf(ip, a+"%s", b)) return 1;
    }
    return 0;
}

protected int is_copy() {
    object ob;

    if (!(ob = find_player(__Name))) return 0;
    if (interactive(ob)) {
        message("logon", "\nThere currently exists an interactive copy of you.\n",
                this_object());
        message("logon", "Do you wish to take over this interactive copy? (y/n) ",
                this_object());
        input_to("disconnect_copy", I_NORMAL, ob);
        return 1;
    }
    seteuid(UID_LOG);
    log_file("enter", sprintf("%s (exec): %s\n", __Name, ctime(time())));
    seteuid(getuid());
    if (exec(ob, this_object())) ob->restart_heart();
    else message("logon", "Problem reconnecting.\n", this_object());
    internal_remove();
    return 1;
}

protected void disconnect_copy(string str, object ob) {
    object tmp;

    if ((str = lower_case(str)) == "" || str[0] != 'y') {
        message("logon", "\nThen please try again later!\n", this_object());
        internal_remove();
        return;
    }
    message("info", "You are being taken over by hostile aliens!", ob);
    if(ob->query_property("inactive")) ob->remove_property("inactive");
    if (!flag)
        tmp = new(OB_USER);
    else {
      if(catch(tmp = new(__ob_name))){
         message("logon", "The file "+__ob_name+" is not available.", this_object());
         internal_remove();
         return;
      }
    }
    exec(tmp, ob);
    exec(ob, this_object());
    destruct(tmp);
    message("logon", "\nAllowing login.\n", ob);
    internal_remove();
}

protected void exec_user() {
    if (MULTI_D->query_prevent_login(__Name)) {
        internal_remove();
        return;
    }
    __Player->set_name(__Name);
    if (!exec(__Player, this_object())) {
        message("logon", "\Problem connecting.\n", this_object());
        internal_remove();
        return;
    }
    __Player->setup();
    if (member_array("neck",__Player->query_limbs()) == -1)
        __Player->add_limb("neck","neck",__Player->query_max_hp(),0,0);
    destruct(this_object());
}

protected void new_pacct(string str) {
    if ((str = lower_case(str)) == "" || str[0] != 'y') {
        message("logon", "\nOk, then enter your real email address: ", this_object());
        input_to("get_email");
        return;
    }
    message("logon", "Please choose a password of at least 5 letters: ", this_object());
    input_to("choose_pacct_password", I_NOECHO | I_NOESC);
}

protected void choose_pacct_password(string str) {
    if (strlen(str) < 5) {
        message("logon", "\nYour password must be at least 5 letters long.\n",
                this_object());
        message("logon", "Please choose another password: ", this_object());
        input_to("choose_pacct_password", I_NOECHO | I_NOESC);
    }
    message("logon", "\nPlease confirm your password choice: ", this_object());
    input_to("confirm_pacct_password", I_NOECHO | I_NOESC, str);
}

protected void confirm_pacct_password(string str2, string str1) {
    if (str1 == str2) {
        __Pacct->set_password(str2 = crypt(str2, 0));

    } else {
        message("logon", "\nPassword entries do not match.  Choose a password: ",
                this_object());
        input_to("choose_pacct_password", I_NOECHO | I_NOESC);
        return;
    }
}

protected void start_ansi() {
        message("logon",
@BELPHY

ANSI color adds very much to your enjoyment of playing the ShadowGate adventure.
The following is an ANSI color test.  If you see color, then you support ANSI.
If you see garbage, then you do NOT support ANSI.  If you don't see color and
you don't see garbage, then ANSI would still probably be a wise decision.

BELPHY
        , this_object());
        message("logon","ANSI color test: "+HIM+"A"+HIG+"N"+HIC+"S"+HIR+"I"+BLU+
                " test"+NOR+"\n\n", this_object());
        message("logon","That should have read 'ANSI test' in multiple
                colors.\n"+
                "Do you support ANSI? [y/n]: ", this_object());
        input_to("ansi_test");
}

protected void ansi_test(string str) {
    str=capitalize(str);
    if (str != "Y" && str != "N") {
        message("logon", "\nPlease enter Y for yes, or N for no.\n",
                this_object());
        message("logon", "Do you support ANSI? [y/n]: ", this_object());
        input_to("ansi_test");
        return;
    }
    if (str == "Y") {
        message("logon", "\nANSI supported turned on.  Use 'setenv TERM "+
                "default' to turn it off.\n",this_object());
        __Player->setenv("TERM","ansi");
        __Player->reset_terminal();
    }
    if (str =="N") {
        message("logon", "\nANSI supported turned off.  Use 'setenv TERM "+
                "ansi' to turn it on.\n",this_object());
        __Player->setenv("TERM","default");
        __Player->reset_terminal();
    }
    message("logon", "\nPlease choose a gender for your new character"+
            " (male or female) : ", this_player());
    input_to("choose_gender");
    return;

}

protected void choose_gender(string str) {
    if (str != "male" && str != "female") {
        message("logon", "\nCute, but pretend to be "+
                "either male or female instead.\n",
                this_object());
        message("logon", "Gender: ", this_object());
        input_to("choose_gender");
        return;
    }
    __Player->set_gender(str);
    __Player->set_email(__Email);
    message("logon", "\nIf you do not mind, enter your "+
            "real name: ",
            this_object());
    input_to("enter_real_name");
}

protected void enter_real_name(string str) {
    if (!str || str == "") str = "Unknown";
    __Player->set_rname(str);
    seteuid(UID_LOG);
    log_file("new_player", sprintf("%s : %s : %s : %s : %s\n",
                                    query_ip_number(), __Name, str, __Player->query_email(),
                                    ctime(time())));
    seteuid(getuid());
    exec_user();
}

protected void idle() {
    message("logon", "\nLogin timed out.\n", this_object());
    internal_remove();
}

protected void receive_message(string cl, string msg) {
    if (member_array(cl,({ "broadcast","shutdown","logon" }) ) == -1 ) return;
    receive(msg);
}

protected void internal_remove() {
    if (__Player) destruct(__Player);
    destruct(this_object());
}

void remove() {
    if (geteuid(previous_object()) != UID_ROOT) return;
    internal_remove();
}
