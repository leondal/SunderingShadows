#include <std.h>
#include <objects.h>

inherit DAEMON;

int help();

int cmd_song(string str) {
    object ob;
    if(!str) return help();
    ob = new("/cmds/bard/songobj");
    ob->set_name(str);
    ob->move(this_player());

    return 1;
}

int help() {
    write(
@OLI
   song:
        Usage: song <name>
       This record a song for you. It will open an editor area 
	   for you to input a new song. The name is the name of the 
	   song <one word> and will be used to reference it later.
	   Emoteat can now be used with stories and songs, the target 
	   of the emoteat is always assumed to be yourself.

       Syntax:
          The commands song recognizes are sing and emote.
          you can write the following:
            sing come to me my love
            come see my joy
            emote waves his hands around
            sing come ...
            emoteat A woman from the audience blows a kiss to $M
          and your audience will see:
            Joe sings come to me my love
            Joe sings come see my joy.
            Joe waves his hands around.
            Joe sings come...
            A woman from the audience blows a kiss to Joe

OLI
    );
    return 1;
}

