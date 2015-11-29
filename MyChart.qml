import QtQuick 2.4

import "QChartGallery.js" as ChartsData
import "."
import "QChart.js"        as Charts

QChart {
      id: chart_doughnut;
      width: chart_width;
      height: chart_height;
      chartAnimated: true;
      chartAnimationEasing: Easing.OutElastic;
      chartAnimationDuration: 2000;
      chartData: ChartsData.ChartDoughnutData;
      chartType: Charts.ChartType.DOUGHNUT;
}
