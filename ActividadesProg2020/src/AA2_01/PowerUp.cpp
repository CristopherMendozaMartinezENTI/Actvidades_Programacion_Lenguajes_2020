#include "PowerUp.h"

PowerUp::PowerUp()
{
}

PowerUp::PowerUp(e_PowerupType _type, std::string _name, Rect _position)
{
	erase = false;

	nRows = 2;
	nColumns = 3;
	texture = "../../res/img/items.png";

	rect = Rect(0, 0, 0, 0);
	frame = Rect(0, 0, 0, 0);
	position = _position;

	rectID = _name + "Rect";
	positionID = _name + "Position";
	textureID = _name + "Texture";
	type = _type;

	Renderer::Instance()->LoadTexture(textureID, texture);

	textureWidth = Renderer::Instance()->GetTextureSize(textureID).x;
	textureHeight = Renderer::Instance()->GetTextureSize(textureID).y;

	frame.w = textureWidth / nColumns;
	frame.h = textureHeight / nRows;
	position.w = rect.w = frame.w;
	position.h = rect.h = frame.h;

	switch (_type)
	{
	case e_PowerupType::ROLLER_SKATER:
		rect.x = frame.w * 1;
		rect.y = frame.h * 1;
		break;
	case e_PowerupType::SHIELD:
		rect.x = frame.w * 2;
		rect.y = frame.h * 1;
		break;
	default:
		break;
	}

	Renderer::Instance()->LoadRect(rectID, Rect());
	Renderer::Instance()->LoadRect(positionID, Rect());

	Renderer::Instance()->SetRect(rectID, rect);
	Renderer::Instance()->SetRect(positionID, position);
}

PowerUp::~PowerUp()
{
}

void PowerUp::Update(InputManager _input, float _deltaTime)
{
}

void PowerUp::Draw()
{
	if (erase == false) Renderer::Instance()->PushSprite(textureID, rectID, positionID);
}

Rect PowerUp::GetPosition()
{
	return position;
}
