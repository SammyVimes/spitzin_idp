import QtQuick 2.4

import "QChartGallery.js" as ChartsData
import "."
import "QChart.js"        as Charts

QChart {
      id: chart_line;
      chartAnimated: true;
      chartAnimationEasing: Easing.OutElastic;
      chartAnimationDuration: 2000;
      chartData: ChartsData.ChartLineData;
      dataGen: ChartsData.LineGen;
      chartType: Charts.ChartType.LINE;
}
