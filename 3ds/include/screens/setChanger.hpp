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

#ifndef _3DZWEI_SET_CHANGER_HPP
#define _3DZWEI_SET_CHANGER_HPP

#include "common.hpp"
#include "structs.hpp"
#include <citro2d.h>
#include <vector>

class SetChanger : public Screen {
public:
	void Draw(void) const override;
	void Logic(u32 hDown, u32 hHeld, touchPosition touch) override;
	SetChanger() { }
private:
	C2D_SpriteSheet previewCards;
	void DrawPreview(void) const;
	void previewLogic(u32 hDown, u32 hHeld, touchPosition touch);

	bool checkForValidate(std::string file);
	Result loadSet(std::string folder);
	Result loadDefault();
	std::string setPath = "";
	int mode = 0;

	const std::vector<Structs::ButtonPos> cardPos = {
		{60, 40, 55, 55},
		{120, 40, 55, 55},
		{180, 40, 55, 55},
		{240, 40, 55, 55},
		{300, 40, 55, 55},

		{60, 100, 55, 55},
		{120, 100, 55, 55},
		{180, 100, 55, 55},
		{240, 100, 55, 55},
		{300, 100, 55, 55}
	};
};

#endif