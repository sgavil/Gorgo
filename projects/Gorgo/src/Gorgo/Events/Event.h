#pragma once
#include "../Core.h"
#include <functional>
#include <string>

namespace Gorgo {

	enum class EventType 
	{
		None = 0, 
		WindowClose, WindowResize, WindowFocus, WindowsMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4),
	};


#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }
	
	
	class GRG_API AEvent {
	public:
		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

	protected:
		bool m_Handled = false;
	};

	class EventDispatcher
	{
		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		EventDispatcher(AEvent& p_event)
			: m_event(p_event) { }

		template<typename T>
		bool Dispatch(EventFn<T> p_func) {
			if (m_event.GetEventType() == T::GetStaticType())
			{
				m_event.m_Handled = p_func(*(T*)&m_event);
				return true;
			}
			return false;
		}

	private:
		AEvent& m_event;
	};

	inline std::ostream& operator<<(std::ostream& os, const AEvent& e) 
	{
		return os << e.ToString();
	}
}