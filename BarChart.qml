import QtQuick 2.4

import "QChartGallery.js" as ChartsData
import "."
import "QChart.js"        as Charts

QChart {
      id: chart_bar;
      width: chart_width;
      height: chart_height;
      chartAnimated: true;
      chartAnimationEasing: Easing.OutBounce;
      chartAnimationDuration: 2000;
      chartData: ChartsData.ChartBarData;
      chartType: Charts.ChartType.BAR;
}

