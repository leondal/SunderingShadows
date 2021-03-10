#include <std.h>

void help();

int cmd_chanset(string str)
{
	int x;
    string *info, command, spc;
	string *chans = ({});

	if(!str)
	{
		tell_object(TP, "You must specify which color code you wish to use!");
		return 1;
	}
	chans = TP->query_channels();
	if(!sizeof(chans))
	{
		tell_object(TP, "Something is wrong... You have no channels?!");
		return 1;
	}

    info = explode(str," ");
    command = info[0];

    if (command != "emote")
    {
        str = " "+str;
        command = "";
    }

    for(x = 0;x < sizeof(chans);x++)
    {
        tell_object(TP, "Adding Alias:  "+chans[x]+command+ " set to "+ chans[x] + str);
        TP->add_alias(chans[x]+command, chans[x] + str);
    }

	return 1;
}



void help(){
   write(
"
%^CYAN%^NAME%^RESET%^

chanset - set message style on all channels you occupy

%^CYAN%^SYNOPSIS%^RESET%^

chanset [emote] %^ORANGE%^%^ULINE%^MESSAGE%^RESET%^

%^CYAN%^DESCRIPTION%^RESET%^

This command will automatically add aliases for each line (channel) you occupy, allowing you to modify appearance of messages on that channel. You  must use $* to substitute your message.

If you want to add emotes, use %^ORANGE%^<chanset emote %^ORANGE%^%^ULINE%^MESSAGE%^RESET%^%^ORANGE%^>%^RESET%^ instead.

%^CYAN%^EXAMPLES%^RESET%^

chanset %%%^^^CYAN%%%^^^{%%%^^^ORANGE%%%^^^ $* %%%^^^CYAN%%%^^^}%%%^^^RESET%%%^^^

    Will make your message \"Hello\" appear on ooc line as 

%^RESET%^ %^CYAN%^{%^ORANGE%^ Hello %^CYAN%^}%^RESET%^

%^CYAN%^SEE ALSO%^RESET%^ 

lines, color
"
       );
}
