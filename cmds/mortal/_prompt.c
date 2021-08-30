#include <std.h>

inherit DAEMON;

void cmd_prompt(string str){
    if(!str)
    {
        TP->setenv("prompt","%^BOLD%^BLACK%^-%^RED%^>%^RESET%^");
        TP->initialize();
        write("Prompt reset.");
        return 1;
    }
    if (sizeof(str) > 1024) {
        tell_object(TP,"Your prompt is too long!");
        return 1;
    }

    TP->setenv("prompt", str);
    TP->initialize();
    write("Prompt changed.");
    return 1;
}
void help(){
    write("
%^CYAN%^NAME%^RESET%^

prompt - change your prompt appearance

%^CYAN%^SYNOPSIS%^RESET%^

prompt [LINE]

%^CYAN%^DESCRIPTION%^RESET%^

This allows you to change your current prompt settings.

When used with no arguments, the prompt will reset to a default of
    %^BOLD%^BLACK%^-%^RED%^>%^RESET%^
Otherwise the prompt will become whatever you type after the prompt
command.

Available codes:
  %^MAGENTA%^$L%^WHITE%^ language
  %^MAGENTA%^$e%^WHITE%^ exp to next level percent
  %^MAGENTA%^$W%^WHITE%^ wimpy percent
  %^MAGENTA%^$h%^WHITE%^ hp
  %^MAGENTA%^$H%^WHITE%^ maximum hp
  %^MAGENTA%^$i%^WHITE%^ hunger level
  %^MAGENTA%^$o%^WHITE%^ thirst level
  %^MAGENTA%^$s%^WHITE%^ stamina percent
  %^MAGENTA%^$S%^WHITE%^ stamina string
  %^MAGENTA%^$x%^WHITE%^ encumbrance level
  %^MAGENTA%^$X%^WHITE%^ maximum encumbrance level
  %^MAGENTA%^$T%^WHITE%^ time of day (word)
  %^MAGENTA%^$t%^WHITE%^ time of day (clock)
  %^MAGENTA%^$_LL%^WHITE%^ light level
  %^MAGENTA%^$d%^WHITE%^ drunkeness

Additional codes:
  %^MAGENTA%^$_EW%^WHITE%^ eldritch warfare
  %^MAGENTA%^$_PF%^WHITE%^ psionic focus
  %^MAGENTA%^$_BI%^WHITE%^ bardic inspiration
  %^MAGENTA%^$r%^WHITE%^ rage status
  %^MAGENTA%^$E%^WHITE%^ eldritch essence
  %^MAGENTA%^$k%^WHITE%^ available ki
  %^MAGENTA%^$K%^WHITE%^ maximum ki
  %^MAGENTA%^$a%^WHITE%^ available arcana
  %^MAGENTA%^$A%^WHITE%^ maximum arcana
  %^MAGENTA%^$z%^WHITE%^ available grace
  %^MAGENTA%^$Z%^WHITE%^ maximum grace
  %^MAGENTA%^$p%^WHITE%^ power points
  %^MAGENTA%^$P%^WHITE%^ maximum power points
  %^MAGENTA%^$f%^WHITE%^ lower case shapeshifted form
  %^MAGENTA%^$B%^WHITE%^ blood hunger percent

Avatars+ only:
  %^MAGENTA%^$I%^WHITE%^ shows True Invis / Mortal Invis / Stealthed status%^RESET%^

Creators+ only:
  %^MAGENTA%^$D%^WHITE%^ shows current directory

%^CYAN%^EXAMPLE%^RESET%^

%^ORANGE%^<prompt Bane >>%^RESET%^
    would look like this
Bane >

%^ORANGE%^<prompt $h/$H >>%^RESET%^
    would look like
300/320 >

%^CYAN%^SEE ALSO%^RESET%^

set, set, speech, adjective, describe, history
");
}
