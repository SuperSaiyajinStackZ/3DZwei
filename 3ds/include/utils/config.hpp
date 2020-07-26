/*
*   This file is part of 3DZwei
*   Copyright (C) 2020 SuperSaiyajinStackZ
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.
*
*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
*   Additional Terms 7.b and 7.c of GPLv3 apply to this file:
*       * Requiring preservation of specified reasonable legal notices or
*         author attributions in that material or in the Appropriate Legal
*         Notices displayed by works containing it.
*       * Prohibiting misrepresentation of the origin of that material,
*         or requiring that modified versions of such material be marked in
*         reasonable ways as different from the original version.
*/

#ifndef _3DZWEI_CONFIG_HPP
#define _3DZWEI_CONFIG_HPP

#include "json.hpp"

#include <3ds.h>
#include <string>

class Config {
public:
	Config();
	void save();
	void initialize();
	void addMissingThings();

	// Card Color.
	u32 cardColor() { return this->v_cardColor; }
	void cardColor(u32 v) { this->v_cardColor = v; if (!this->changesMade)	this->changesMade = true; }
	// Bar Color.
	u32 barColor() { return this->v_barColor; }
	void barColor(u32 v) { this->v_barColor = v; if (!this->changesMade)	this->changesMade = true; }
	// BG Color.
	u32 bgColor() { return this->v_bgColor; }
	void bgColor(u32 v) { this->v_bgColor = v; if (!this->changesMade)	this->changesMade = true; }
	// Text Color.
	u32 textColor() { return this->v_textColor; }
	void textColor(u32 v) { this->v_textColor = v; if (!this->changesMade)	this->changesMade = true; }
	// Button Color.
	u32 buttonColor() { return this->v_buttonColor; }
	void buttonColor(u32 v) { this->v_buttonColor = v; if (!this->changesMade)	this->changesMade = true; }
	// Selector Color.
	u32 selectorColor() { return this->v_selectorColor; }
	void selectorColor(u32 v) { this->v_selectorColor = v; if (!this->changesMade)	this->changesMade = true; }
	// Card Delay.
	int delay() { return this->v_delay; }
	void delay(int v) { this->v_delay = v; if (!this->changesMade)	this->changesMade = true; }
	// Debug.
	bool debug() { return this->v_debug; }
	// Card file.
	std::string cardFile() { return this->v_cardFile; }
	void cardFile(std::string v) { this->v_cardFile = v; if (!this->changesMade)	this->changesMade = true; }
	// Language.
	int language() { return this->v_language; }
	void language(int v) { this->v_language = v; if (!this->changesMade)	this->changesMade = true; }
	// Set.
	std::string Set() { return this->v_Set; }
	void Set(std::string v) { this->v_Set = v; if (!this->changesMade)	this->changesMade = true; }
	// BGs.
	std::string BG() { return this->v_BG; }
	void BG(std::string v) { this->v_BG = v; if (!this->changesMade)	this->changesMade = true; }
	// Version.
	int version() { return this->v_version; }
	void version(int v) { this->v_version = v; if (!this->changesMade)	this->changesMade = true; }

	// Mainly helper.
	bool getBool(const std::string &key);
	void setBool(const std::string &key, bool v);
	int getInt(const std::string &key);
	void setInt(const std::string &key, int v);
	std::string getString(const std::string &key);
	void setString(const std::string &key, const std::string &v);
private:
	nlohmann::json json; // Our private JSON file.
	bool changesMade = false;
	int configVersion = 2;

	// Color variables and more.
	u32 v_cardColor, v_barColor, v_bgColor, v_textColor, v_buttonColor, v_selectorColor;
	int v_delay, v_language, v_version;
	bool v_debug;
	std::string v_cardFile, v_Set, v_BG;
};

#endif