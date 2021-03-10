//char_poster2.c - Poster #2 for character info. room

#include <std.h>

inherit OBJECT;

void create(){
    ::create();
    set_name("green poster");
    set_id( ({"Green poster", "green poster", "poster"}) );
    set_short("%^BOLD%^%^GREEN%^Green poster%^RESET%^");
    set_long(
@STYX
%^BOLD%^%^GREEN%^SPEECH and ACTIONS for CUSTOMIZING YOUR CHARACTER%^RESET%^
\nThe %^BOLD%^%^BLUE%^<speech>%^RESET%^ emote customizes how you come across when you use <say>.  Type 'speech mumble' to change from 'Bob says: blah blah' to 'Bob mumbles: blah blah'.  NOTE:  The mud WILL add an 's' to the end of the first word you use after 'speech' for what others see.  So, if you type 'speech mumbles softly', you will see 'You mumbles softly: blah blah' and others will see 'Bob mumbless softly: blah blah'.
\n\nIn/out %^BOLD%^%^BLUE%^<message>%^RESET%^(s) are what others see when you enter and leave a room instead of just 'Bob enters.'  
\nType 'message in trudges in' to show 'Bob trudges in' when you enter a room.
\nType 'message out stumbles off' to show 'Bob stumbles off (east/west, etc.)' when you leave. 
\nType %^BOLD%^%^BLUE%^'review' %^RESET%^to see your messages.  However, some you see there can't be set my mortals or are only for wizzes.  The %^BOLD%^%^GREEN%^$D%^RESET%^ at the end of MOUT is always there and fills in the Direction you leave by.  So, your message out will always end with a direction.  
Note - do NOT use the color black anywhere since for most displays it will be invisible.  Setting it to hide the direction you leave is considered cheating and will be dealt with accordingly.
\n%^BOLD%^%^MAGENTA%^U S I N G   C O L O R S%^RESET%^
Type 'help color' to see the color commands available.  Note - the color words inside the %^ characters must be in capital letters.  If you use colors in your adjective, put a '%^ RESET %^' (without the spaces) at the end so your colors don't carry over to others in the room.
STYX
    );
    set_weight(10000);
    set_property("no animate",1);
}
