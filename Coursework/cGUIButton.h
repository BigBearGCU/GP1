#pragma once

#include "cGUILabel.h"
#include <functional>

class cGUIButton :
	public cGUILabel
{
private:
	glm::vec4 highlightColor;
	glm::vec4 savedColor;
	std::function<void()> onClick;

public:
	cGUIButton(cTexture *pTexture, RECTF pRect, string pText, std::function<void()> pOnClick);
	~cGUIButton() {}

	void SetBackgroundColor(glm::vec4 pBkgdColor) { savedColor = pBkgdColor; }
	void SetHighlightColor(glm::vec4 pHighlightColor) { highlightColor = pHighlightColor; }

	void Update();
	void Render();
};

