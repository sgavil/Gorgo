#pragma once
#include "Event.h"
#include <sstream>

namespace Gorgo {

	class GRG_API WindowResizeEvent : public AEvent
	{
	public:
		WindowResizeEvent(unsigned int p_width, unsigned int p_height)
			: m_width(p_width), m_height(p_height) { }

		inline unsigned int GetWidth() const { return m_width; }
		inline unsigned int GetHeight() const { return m_height; }

		std::string ToString() const override 
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << m_width << ", " << m_height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);
	private:
		unsigned int m_width, m_height;
	};

	class GRG_API WindowCloseEvent : public AEvent
	{
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	};

	class GRG_API AppTickEvent : public AEvent
	{
	public:
		AppTickEvent() {}

		EVENT_CLASS_TYPE(AppTick);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	};

	class GRG_API AppUpdateEvent : public AEvent
	{
	public:
		AppUpdateEvent() {}

		EVENT_CLASS_TYPE(AppUpdate);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	};

	class GRG_API AppRenderEvent : public AEvent
	{
	public:
		AppRenderEvent() {}

		EVENT_CLASS_TYPE(AppRender);
		EVENT_CLASS_CATEGORY(EventCategoryApplication);

	};

}