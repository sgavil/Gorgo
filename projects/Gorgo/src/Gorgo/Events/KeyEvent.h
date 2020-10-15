#pragma once
#include "../Core.h"
#include "Event.h"

#include <sstream>
namespace Gorgo {

	class GRG_API KeyEvent : public AEvent {
	public:
		inline int GetKeyCode() { return m_keyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

	protected:
		KeyEvent(int p_keyCode)
			: m_keyCode(p_keyCode) {

		}

		int m_keyCode;
	};

	class GRG_API KeyPressedEvent : public KeyEvent 
	{
	public:
		KeyPressedEvent(int p_keyCode, int p_repeatCount)
			: KeyEvent(p_keyCode), m_repeatCount(p_repeatCount) {}

		inline int GetRepeatCount() const { return m_repeatCount; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_keyCode << " (" << m_repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);
		
		

	private:
		int m_repeatCount;

	};

	class GRG_API KeyReleasedEvent : public KeyEvent 
	{
	public:
		KeyReleasedEvent(int p_keyCode) 
			: KeyEvent(p_keyCode) {}

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_keyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased);

	};

}