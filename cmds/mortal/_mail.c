#include <std.h>
#include <objects.h>

inherit DAEMON;

int cmd_mail(string str) {
    object ob;
    string str1, str2;

    if (!TP->query_level()) return notify_fail("Please create a character before using this command!");
    if(str) {
        if(strsrch(str, "avatar") != -1) {
            if(!avatarp(TP)){
                write("%^BOLD%^%^MAGENTA%^Please use the <avatarmail> command for things you "
                      "wish to have reviewed by the avatars/immortals.\n");
                return 1;
            }
        }
        if(str == "law" || str == "lawmail" ||
           ( (sscanf(str, "%s %s", str1, str2) != -1)
             && (str1 == "law" || str2 == "law" || str1 == "lawmail" || str2 == "lawmail")))
        {
            write("%^BOLD%^%^WHITE%^Please use the <lawmail> command for things you "
                  "wish to have reviewed by the admins who handle law issues.");
            return 1;
        }
    }
    ob = new(OB_POSTAL);
    ob->move(this_player());
    ob->start_mail(str);
    return 1;
}

void help() {
    write(
        "
%^CYAN%^NAME%^RESET%^

mail - send someone a mail

%^CYAN%^SYNOPSIS%^RESET%^

mail [%^ORANGE%^%^ULINE%^NAME%^RESET%^]

%^CYAN%^DESCRIPTION%^RESET%^

Without arguments will put you into mail client to read and manage your mail. This client is coded to behave much like standard mail(1) on unix systems. The internal help is accessed with %^MAGENTA%^?%^RESET%^ command, or with %^ORANGE%^<help mail_syntax>%^RESET%^.

With argument %^ORANGE%^%^ULINE%^NAME%^RESET%^ will put you into an editor where you can type mail for another player %^ORANGE%^%^ULINE%^NAME%^RESET%^. Recognized name won't work for this purpose, you must know name player used for character creation.

This form of communication is considered to be Out Of Character, between players, not between characters.

%^CYAN%^SEE ALSO%^RESET%^

mail_syntax, finger, account, who, tell, say, yell
");
}
