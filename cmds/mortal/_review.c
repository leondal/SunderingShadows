//	/bin/high_mortal/_review.c
//	from the Nightmare mudlib
//	created by Sulam 21 december 1991
//      recoded by Obsidian@ShadowGate 14 December 1999

#include <std.h>

inherit DAEMON;

int
cmd_review()
{
	write("Your messages are:\n");
        write("TITLE:   " + (string) this_player()->query_title() + "\n");
        write("MIN:     "+
        replace_string(replace_string(TP->query_min(TP), "Someone",
        capitalize(TP->query_name()), 1), " %^BOLD%^%^GREEN%^(invisible)", "")+
        "\n");
        write("MOUT:    "+
        replace_string(replace_string(TP->query_mout("$D",TP),"Someone",
        capitalize(TP->query_name()), 1), " %^BOLD%^%^GREEN%^(invisible)", "")+
        "\n");
        write("MMIN:    "+
        replace_string(replace_string(TP->query_mmin(TP),"Someone",
        capitalize(TP->query_name()), 1), " %^BOLD%^%^GREEN%^(invisible)", "")+
        "\n");
        write("MMOUT:   "+
        replace_string(replace_string(TP->query_mmout(TP),"Someone",
        capitalize(TP->query_name()), 1), " %^BOLD%^%^GREEN%^(invisible)", "")+
        "\n");
        write("MHOME:   "+
        replace_string(TP->query_mhome(),"Someone",
        capitalize(TP->query_name()),1)+"\n");
        write("MDEST:   "+
        replace_string(TP->query_mdest(),"Someone",
        capitalize(TP->query_name()),1)+"\n");
        write("MCLONE:  "+
        replace_string(TP->query_mclone(),"Someone",
        capitalize(TP->query_name()),1)+"\n");
        write("MVIS:    "+
        replace_string(TP->query_mvis(),"Someone",
        capitalize(TP->query_name()),1)+"\n");
        write("MINVIS:  "+
        replace_string(TP->query_minvis(),"Someone",
        capitalize(TP->query_name()),1)+"\n");
	return 1;
}

int
help() {
  write("Command: review\nSyntax: review\n"+
        "This command shows you what your basic environmental messages are\n"+
        "currently set to.  In order to change them you need to use\n"+
        "the set command (for wizards), the message command (for players).\n");
  return 1;
}
/* EOF */


