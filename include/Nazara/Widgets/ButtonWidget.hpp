// Copyright (C) 2025 Jérôme "SirLynix" Leclercq (lynix680@gmail.com)
// This file is part of the "Nazara Engine - Widgets module"
// For conditions of distribution and use, see copyright notice in Export.hpp

#pragma once

#ifndef NAZARA_WIDGETS_BUTTONWIDGET_HPP
#define NAZARA_WIDGETS_BUTTONWIDGET_HPP

#include <Nazara/Core/Color.hpp>
#include <Nazara/Graphics/SlicedSprite.hpp>
#include <Nazara/Graphics/TextSprite.hpp>
#include <Nazara/Widgets/BaseWidget.hpp>
#include <Nazara/Widgets/WidgetStyleFactory.hpp>
#include <Nazara/Widgets/WidgetTheme.hpp>

namespace Nz
{
	class AbstractTextDrawer;

	class NAZARA_WIDGETS_API ButtonWidget : public BaseWidget
	{
		public:
			using StyleFactory = WidgetStyleFactory<ButtonWidget, ButtonWidgetStyle>;

			ButtonWidget(BaseWidget* parent, const StyleFactory& styleFactory = nullptr);
			ButtonWidget(const ButtonWidget&) = delete;
			ButtonWidget(ButtonWidget&&) = delete;
			~ButtonWidget() = default;

			inline void Disable();
			void Enable(bool enable = true);

			inline bool IsEnabled() const;

			void UpdateText(const AbstractTextDrawer& drawer);

			ButtonWidget& operator=(const ButtonWidget&) = delete;
			ButtonWidget& operator=(ButtonWidget&&) = delete;

			NazaraSignal(OnButtonTrigger, const ButtonWidget* /*button*/);

		private:
			void Layout() override;

			void OnMouseEnter() override;
			bool OnMouseButtonPress(int x, int y, Mouse::Button button) override;
			bool OnMouseButtonRelease(int x, int y, Mouse::Button button) override;
			void OnMouseExit() override;

			void OnRenderLayerUpdated(int baseRenderLayer) override;

			std::unique_ptr<ButtonWidgetStyle> m_style;
			bool m_isEnabled;
	};
}

#include <Nazara/Widgets/ButtonWidget.inl>

#endif // NAZARA_WIDGETS_BUTTONWIDGET_HPP
