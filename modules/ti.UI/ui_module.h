/**
 * Appcelerator Titanium - licensed under the Apache Public License 2
 * see LICENSE in the root folder for details on the license.
 * Copyright (c) 2008 Appcelerator, Inc. All Rights Reserved.
 */
#ifndef _UI_MODULE_H_
#define _UI_MODULE_H_

#include <kroll/kroll.h>

namespace ti {
	class UIBinding;
	class Menu;
	class MenuItem;
	class TrayItem;
	class UserWindow;

	typedef SharedPtr<UserWindow> SharedUserWindow;
	typedef SharedPtr<UIBinding> SharedUIBinding;
	typedef SharedPtr<Menu> SharedMenu;
	typedef SharedPtr<MenuItem> SharedMenuItem;
	typedef SharedPtr<TrayItem> SharedTrayItem;
}

#include <JavaScriptCore/JSObjectRef.h>
#include <JavaScriptCore/JSStringRef.h>
#include <JavaScriptCore/JSContextRef.h>

#include <iostream>
#include "javascript_module.h"
#include "window_config.h"
#include "user_window.h"
#include "menu.h"
#include "menu_item.h"
#include "tray_item.h"
#include "ui_binding.h"

#ifdef OS_LINUX
#include "gtk/ui_module_gtk.h"
#include "gtk/script_evaluator.h"

#elif defined(OS_OSX)
#include "osx/ui_module_osx.h"

#elif defined(OS_WIN32)
#include "win32/ui_module_win32.h"
#endif

namespace ti {

	class UIModule : public kroll::Module
	{
		KROLL_MODULE_CLASS(UIModule)

		public:
		static UIModule* GetInstance() { return instance_; }
		SharedUIBinding GetUIBinding() { return uiBinding; }
		void Exiting(int exitcode);
		void Start();
		static bool IsResourceLocalFile(std::string string);

		protected:
		DISALLOW_EVIL_CONSTRUCTORS(UIModule);
		static UIModule* instance_;
		SharedUIBinding uiBinding;

	};
}

#endif
