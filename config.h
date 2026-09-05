#pragma once

/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 0;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 0;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
#define COORDINATES_STYLE "[x%d y%d]" /* The style of coordinates displayed in bar, do not remove %d. */

static MAYBE_CONST char normbgcolor[]           = "#222222";
static MAYBE_CONST char normbordercolor[]       = "#222222";
static MAYBE_CONST char normfgcolor[]           = "#bbbbbb";
static MAYBE_CONST char selfgcolor[]            = "#eeeeee";
static MAYBE_CONST char selbordercolor[]        = "#e6e6e6";
static MAYBE_CONST char selbgcolor[]            = "#9e9e9e";
static MAYBE_CONST char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm] = { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]  = { selfgcolor,  selbgcolor,  selbordercolor  },
};

#define CENTER_NEW_FLOATING_WINDOWS 1 // so, basically, it does what it says. (make 0 to turn off)
#define NEW_FLOATING_WINDOWS_APPEAR_UNDER_CURSOR 0 // so, basically, it does what it says. (make 0 to turn off) 

#if GAPS
static const unsigned int gappx = 5;
#endif

#if BAR_HEIGHT
static const int user_bh = 30;
#endif

#if BAR_PADDING
static const int top_vertpad = 0;          /* top vertical padding of bar */ 
static const int bottom_vertpad = 8;       /* bottom vertical padding of bar */
static const int left_sidepad = 550;         /* left horizontal padding of bar */
static const int right_sidepad = 550;        /* right horizontal padding of bar */
#endif

#define BAR_ALWAYS_ON_TOP 1 /* Makes internal bar on top of other windows. */

#if EXTERNAL_BARS
#define EXTERNAL_BARS_ALWAYS_ON_TOP 1 /* Makes external bars on top of other windows. */
#endif

#if INFINITE_TAGS
#define PINNED_WINDOWS_ALWAYS_ON_TOP 1 /* Makes pinned windows on top of other windows */
#endif

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

#if OCCUPIED_TAGS_DECORATION
static const char *occupiedtags[] = { "1+", "2+", "3+", "4+", "5+", "6+", "7+", "8+", "9+" };
#endif

#if INFINITE_TAGS
#define MOVE_CANVAS_STEP 120 /* Defines how many pixel will be jumped when using movecanvas function */
#endif

#if INFINITE_TAGS && IT_SHOW_COORDINATES_IN_BAR
#define COORDINATES_DIVISOR 10 /* Defines by what number coordinates on the bar will be divided, can be used for making numbers smaller which makes navigation easier */
#endif

#if MOVE_RESIZE_WITH_KEYBOARD
#define MOVE_WITH_KEYBOARD_STEP 50 /* Defines by how many pixels windows will be resized with keyboard */
#define RESIZE_WITH_KEYBOARD_STEP 50 /* Defines by how many pixels windows will be resized with keyboard */
#endif

#if AUTOSTART
/* vxwm will execute this on startup (can be skipped with -ignoreautostart vxwm flag). */

static const char *const autostart[] = {
    "pipewire", NULL,
    "pipewire-pulse", NULL,
    "vcompmgr", NULL,
    "tgwsproxy", NULL,
    "Telegram", NULL,
    "firefox-bin", NULL,
    "sh", "-c", "xrandr --output HDMI-1 --mode 1920x1080 --rate 144 --output eDP-1 --off", NULL,
    "sh", "-c", "feh --bg-fill /home/usary/Downloads/huawei-dark-mode-5800x3200-26686.png", NULL,
    NULL
};
#endif

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
#if LOCK_MOVE_RESIZE_REFRESH_RATE
static const int refreshrate = 580;  /* refresh rate (per second) for client move/resize, set it to your monitor refresh rate or double of that*/
#endif //LOCK_MOVE_RESIZE_REFRESH_RATE
static const Layout layouts[] = {
	/* symbol     arrange function */
  { "><>",      NULL },    /* no layout function means floating behavior */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define ALTERNATE_MODKEY Mod1Mask

#define SCROLL_UP Button4
#define SCROLL_DOWN Button5
#define TAGKEYS(KEY,TAG) \
	{ MODKEY, KEY, view, {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY, toggletag, {.ui = 1 << TAG} },



/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", NULL };

static const char *termcmd[] = { "kitty", NULL };
static const char *filemanagercmd[] = { "nautilus", NULL };

#if ZOOM
static const char *zoomin[] = { "vcompmgr", "-Z", "+0.15", NULL }; // zoom in
static const char *zoomout[] = { "vcompmgr", "-Z", "-0.15", NULL }; // zoom out
static const char *zoomreset[] = { "vcompmgr", "-Z", "1", NULL }; // set zoom to 1
#endif

static void focuscenter(const Arg *arg)
{
	focusstack(arg);
	centerwindow(NULL);
}

static const Key keys[] = {
{ ALTERNATE_MODKEY, XK_Tab, focuscenter, {.i = +1} },
{ ALTERNATE_MODKEY|ShiftMask, XK_Tab, focuscenter, {.i = -1} },
{ MODKEY, XK_q, spawn, {.v = termcmd} },
{ MODKEY, XK_e, spawn, {.v = filemanagercmd} },
{ MODKEY, XK_c, killclient, {0} },
{ MODKEY, XK_f, togglefullscr, {0} },
{ MODKEY, XK_g, setlayout, {0} },
{ MODKEY, XK_v, focusstack, {.i = +1} },
{ MODKEY, XK_t, swapmaster, {0} },
TAGKEYS(XK_1, 0)
TAGKEYS(XK_2, 1)
TAGKEYS(XK_3, 2)
TAGKEYS(XK_4, 3)
TAGKEYS(XK_5, 4)
TAGKEYS(XK_6, 5)
TAGKEYS(XK_7, 6)
TAGKEYS(XK_8, 7)
TAGKEYS(XK_9, 8)
{ MODKEY|ShiftMask, XK_s, spawn, SHCMD("maim -s | xclip -selection clipboard -t image/png") },
{ MODKEY, XK_r, spawn, SHCMD("vcompmgr -Z 1") },
};

/* button definitions */
static const Button buttons[] = {
{ ClkClientWin, MODKEY, Button1, movemouse, {0} },
{ ClkClientWin, MODKEY, Button3, resizemouse, {0} },
{ ClkRootWin, MODKEY, Button2, movecanvasmouse, {.f = 1.5} },
{ ClkClientWin, MODKEY, Button2, movecanvasmouse, {.f = 1.5} },
{ ClkRootWin, MODKEY, SCROLL_UP, spawn, SHCMD("vcompmgr -Z $(echo $(vcompmgr -G) + 0.15 | bc)") },
{ ClkRootWin, MODKEY, SCROLL_DOWN, spawn, SHCMD("vcompmgr -Z $(echo $(vcompmgr -G) - 0.15 | bc)") },
{ ClkClientWin, MODKEY, SCROLL_UP, spawn, SHCMD("vcompmgr -Z $(echo $(vcompmgr -G) + 0.15 | bc)") },
{ ClkClientWin, MODKEY, SCROLL_DOWN, spawn, SHCMD("vcompmgr -Z $(echo $(vcompmgr -G) - 0.15 | bc)") },
};
