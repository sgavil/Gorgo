#pragma once
#include "Event.h"
#include <sstream>

namespace Gorgo {

	class GRG_API MouseMovedEvent : public AEvent
	{
	public:
		MouseMovedEvent(float p_x, float p_y)
			: m_mouseX(p_x), m_mouseY(p_y) { }

		EVENT_CLASS_TYPE(MouseMoved);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

		inline float GetMouseX() const { return m_mouseX; }
		inline float GetMouseY() const { return m_mouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
			return ss.str();
		}

	private:
		float m_mouseX;
		float m_mouseY;
	};

	class GRG_API MouseScrolledEvent : public AEvent {
	public:
		MouseScrolledEvent(float p_offsetX, float p_offsetY)
			: m_offsetX(p_offsetX), m_offsetY(p_offsetY) { }

		EVENT_CLASS_TYPE(MouseScrolled);
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput);

		inline float GetOffsetX() const { return m_offsetX; }
		inline float GetOffsetY() const { return m_offsetY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_offsetX << ", " << m_offsetY;
			return ss.str();
		}

	private:
		float m_offsetX;
		float m_offsetY;
	};
}