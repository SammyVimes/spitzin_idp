import QtQuick 2.4

import "QChartGallery.js" as ChartsData
import "."
import "QChart.js"        as Charts

QChart {
      id: chart_bar;
      chartAnimated: true;
      chartAnimationEasing: Easing.OutBounce;
      chartAnimationDuration: 2000;
      chartData: ChartsData.ChartBarData;
      dataGen: ChartsData.BarGen;
      chartType: Charts.ChartType.BAR;
}

