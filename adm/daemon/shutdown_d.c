//  Shutdown Daemon for ShadowGate v2.0
//  Thorn@ShadowGate
//  950506
//  /adm/daemon/shutdown_d.c

#include <std.h>
#include <objects.h>
#include <security.h>

// Now MAX_MEMORY is messured in Megs - Firedragon 12/7/2004
#define MAX_MEMORY 10240
#define DEFAULT_WARNING_TIME 20
#define TEST_INTERVAL 3
#define LAG_MINUTES 3

#define TEST 0
#define STANDARD 1
#define MEMORY 2
#define CPU 3
#define MANUAL 4
#define EMERGENCY 5
#define OTHER 6

inherit DAEMON;

object* queue;
int timeLeft, armShutdown, loginAllow;
int shuttingDown, time_estimate;

create()
{
    ::create();
    shuttingDown = 0;
    initShutdownDaemon();
    seteuid(UID_SHUTDOWN);
}

int initShutdownDaemon()
{
    queue = ({ });
    timeLeft = -1;
    loginAllow = 1;
    armShutdown = 0;
    time_estimate = time() + (TEST_INTERVAL * 60) + (LAG_MINUTES * 60);
    return 1;
}

int shuttingDown()
{
    return shuttingDown;
}

int notifyUsers(string msg)
{
    message("broadcast", "%^BOLD%^%^RED%^[Shutdown]%^RESET%^ " + msg, users());
    return 1;
}

int startShutdown(int type, int time)
{
    remove_call_out("countDown");
    if (geteuid(TO) != UID_SHUTDOWN) {
        return 0;
    }
    if (type != TEST) {
        shuttingDown = 1;
    }
    switch (type) {
    case TEST:
        if (time < 1) {
            break;
        }
        timeLeft = time * 60;
        notifyUsers("Testing Shutdown Daemon (no shutdown will occur)");
        notifyUsers("Reboot in " + time + " minutes!");
        countDown();
        return TEST;
        break;
    case STANDARD:
        timeLeft = DEFAULT_WARNING_TIME * 60;
        notifyUsers("Regularly Scheduled Reboot Starting....");
        enableShutdown();
        countDown();
        return STANDARD;
        break;
    case MEMORY:
        timeLeft = DEFAULT_WARNING_TIME * 30;
        notifyUsers("RAM usage limit exceeded.  Auto-rebooting....");
        enableShutdown();
        call_out("countDown", 60);
        return MEMORY;
        break;
    case CPU:
        timeLeft = DEFAULT_WARNING_TIME * 30;
        notifyUsers("CPU Usage Limit Exceeded, Rebooting....");
        enableShutdown();
        countDown();
        return CPU;
        break;
    case MANUAL:
        if (time < 1) {
            break;
        }
        timeLeft = time * 60;
        notifyUsers("Manual Reboot....");
        enableShutdown();
        countDown();
        return MANUAL;
        break;
    case EMERGENCY:
        timeLeft = 60;
        notifyUsers("%^BOLD%^***Emergency Reboot***%^RESET%^");
        notifyUsers("Saving Players and Rebooting Immediately.");
        enableShutdown();
        executeShutdown();
        return EMERGENCY;
        break;
    case OTHER:
        timeLeft = 60;
        notifyUsers("%^BOLD%^***Emergency Reboot***%^RESET%^");
        notifyUsers("Saving Players and Rebooting Immediately.");
        enableShutdown();
        executeShutdown();
        return OTHER;
        break;
    }
    return 0;
}

int countDown()
{
    if (!timeLeft) {
        executeShutdown();
        return 2;
    }
    if (timeLeft < 11) {
        notifyUsers("Attention: Shutdown in 10 seconds!  Final Warning!\n");
        timeLeft = 0;
        call_out("countDown", 10);
        return 1;
    }
    if (timeLeft < 121 && timeLeft > 61) {
        notifyUsers("Attention: Shutdown in two minutes!\n");
        timeLeft -= 60;
        call_out("countDown", 60);
        return 1;
    }
    if (timeLeft < 61) {
        notifyUsers("Attention: Shutdown in one minute!\n");
        timeLeft -= 50;
        call_out("countDown", 50);
        return 1;
    }
    if (timeLeft > 3600) {
        notifyUsers("Attention: Shutdown in " + parse_time(timeLeft) + "\n");
        timeLeft -= 1200;
        call_out("countDown", 1200);
        return 1;
    }
    if (timeLeft > 600) {
        notifyUsers("Attention: Shutdown in " + parse_time(timeLeft) + "\n");
        timeLeft -= 600;
        call_out("countDown", 600);
        return 1;
    }

    notifyUsers("Attention: Shutdown in " + timeLeft / 60 + " minutes.\n");

    timeLeft -= 60;
    call_out("countDown", 60);
    return 1;
}

int executeShutdown()
{
    int all, x;
    object imm;

    if (!armShutdown) {
        return notifyUsers("Shutdown will not be executed.\n");
    }
    queue = users();
    loginAllow = 0;
    all = sizeof(queue);
    for (x = 0; x < all; x++) {
        queue[x]->toggle_quit(0);
    }
    notifyUsers("Shutting down within moments. Be back in a few minutes!\n");
    notifyUsers("Quit has been disabled for all remaining players.\n");

    for (x = 0; x < all; x++) {
        imm = queue[x];
        if (!imm) {
            notifyUsers("Error in reboot! (executeShutdown)\n");
            return 0;
            break;
        }
        imm->toggle_quit(1);
        imm->quit();
    }
    shutdown();
    return 1;
}

int enableShutdown()
{
    if (armShutdown) {
        return -1;
    }
    armShutdown = 1;
    return 1;
}

int disableShutdown()
{
    if (!armShutdown) {
        return -1;
    }
    armShutdown = 0;
    return 1;
}

protected void cancel_it()
{
    cancelShutdown();
    return;
}

int cancelShutdown()
{
    disableShutdown();
    remove_call_out("countDown");
    if (timeLeft <= 10) {
        remove_call_out("executeShutdown");
    }
    notifyUsers("Attention: Shutdown cancelled. No reboot will occur.\n");
    timeLeft = 0;
    shuttingDown = 0;
    return 1;
}

void do_armageddon(int tmp)
{
    startShutdown(MANUAL, tmp);
    return;
}

int query_login_allow()
{
    return loginAllow;
}

int clean_up()
{
    return 0;
}

int query_time_left()
{
    return timeLeft;
}
