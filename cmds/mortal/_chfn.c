//      /bin/user/_chfn.c
//      from the Nightmare Mudlib
//      command to change finger info
//      created by Sulam@TMI 911208
//      modified for the Nightmare 3.0 security by Descartes of Borg 930814

#include <std.h>
#include <security.h>

inherit DAEMON;

int cmd_chfn(string arg) {
    if( (string)this_player()->query_name() == "guest" ) return 0;
    write("Changing finger information on " +
	(string) this_player()->query_name() + " at ShadowGate.\n");
    write("Default values are printed inside '[]'.\n");
    write("To accept the default, type <return>.\n");
    write("\n");
    write("Name ["+(string)this_player()->query_rname()+"] : ");
    input_to("new_name");
    return 1;
}

protected void new_name(string rname)
{
    if( rname && (strlen( rname ) > 0) )
    {
        seteuid(UID_USERACCESS);
        this_player()->set_rname(rname);
        seteuid(getuid());
        this_player()->save_player((string)this_player()->query_name());
    }
    write("Email address ["+this_player()->query_email()+"] : ");
    input_to("new_email");
}

void warning_display()
{
    write ("Please input any information you wish to show up at the bottom of your finger display.

You may use it to allow other players to contact you OOG. Do NOT use any such information for harassment and if you are harassed, please report by whom.

Displaying any information here is entirely voluntary and not required. However, whatever you input here will be available to anyone who uses the finger command. You are free to include whatever you wish to include.

If you do not enter anything then ** will simply exit the command and nothing will be visible to players who use the finger command on you.

Type ** to exit.");
}

protected void new_email(string e)
{
    string user,host, olde;
    olde=this_player()->query_email();
    if (!e && stringp(olde) && (strlen(olde) > 6))
    {
        // Show me a valid email address with 6 characters and I
        // will be amazed.
        write ("Leaving email as ["+olde+"].");
        warning_display();
        input_to("ooc_contact");
        return;
    }
    else if (stringp(e) && (strlen(e) <= 6))
    {
        write("Sorry, I don't believe you.\nAt least TRY to make it valid!\n");
        write("Email address ["+olde+"] : ");
        input_to("new_email");
        return;
    }

    if( (strlen(e) > 0 ) && sscanf(e,"%s@%s",user,host) != 2)
    {
        write("Email address must be in the form user@host.\nPlease input again.");
        write("Email address ["+olde+"] : ");
        input_to("new_email");
        return;
    }
    if (e == olde)
    {
        warning_display();
        input_to("ooc_contact");
        return;
    }
    if( e && strlen( e ) > 0 )
    {
        seteuid(UID_USERACCESS);
        this_player()->set_email(e);
        seteuid(getuid());
        seteuid(UID_LOG);
        log_file("player/chfn",this_player()->query_name()+":"+olde+" -> "+e+" .\n");
        seteuid(getuid());
        warning_display();
        //write("OOG Contact Information:\n");
        input_to("ooc_contact", "");
        return;
    }
    return 1;
}

protected void ooc_contact(string cont, string contact)
{
    if(cont == "**")
    {
        if(stringp(contact) && contact != "")
        {
            write("Setting ooc contact information to \n\n"+contact);
            this_player()->set("ooc contact", contact);
            return;
        }
        else
        {
            write("Exiting chfn, without setting any additional information.");
            this_player()->delete("ooc contact");
            return;
        }
    }
    if(!cont || cont == "")
    {
        if(!stringp(contact)) contact = "";
        else contact += "\n";
        write("Inserting carriage return. Enter any additional OOG contact information. Or enter ** to exit.");
        input_to("ooc_contact", contact);
        return;
    }
    else
    {
        if(stringp(contact)) contact += cont;
        else contact = cont;
        write("Enter any additional OOG contact information. Or enter ** to exit.");
        input_to("ooc_contact", contact);
        return;
    }
}

int
help() {
  write("
%^CYAN%^NAME%^RESET%^

chfn - change user information

%^CYAN%^DESCRIPTION%^RESET%^

Asks and updates your information for finger command.

With exception of an e-mail, providing data here is strictly voluntary.

Reminder, do no use information provided by others to harass them.

%^CYAN%^SEE ALSO%^RESET%^

finger, who, set, passwd, ignore
"
  );
  return 1;
}
