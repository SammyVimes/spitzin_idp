// QChartGallery.js ---
//
// Author: Julien Wintz
// Created: Thu Feb 13 23:43:13 2014 (+0100)
// Version:
// Last-Updated:
//           By:
//     Update #: 13
//

// Change Log:
//
//

// /////////////////////////////////////////////////////////////////
// Line Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartLineData = {
      labels: ["Понедельник","Вторник","Среда","Четверг","Пятница","СУббота","Воскресенье"],
    datasets: [{
               fillColor: "rgba(220,120,120,0.5)",
             strokeColor: "rgba(220,120,120,1)",
              pointColor: "rgba(220,120,120,1)",
        pointStrokeColor: "#ffffff",
                    data: [6,5,9,8,5,5,4]
    }, {
               fillColor: "rgba(151,230,180,0.5)",
             strokeColor: "rgba(151,230,180,1)",
              pointColor: "rgba(151,230,180,1)",
        pointStrokeColor: "#ffffff",
                    data: [2,4,4,1,9,2,10]
    }]
}

// /////////////////////////////////////////////////////////////////
// Polar Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartPolarData = [{
    value: 30,
    color: "#D97041"
 }, {
    value: 90,
    color: "#C7604C"
 }, {
    value: 24,
    color: "#21323D"
 }, {
    value: 58,
    color: "#9D9B7F"
 }, {
    value: 82,
    color: "#7D4F6D"
 }, {
    value: 8,
    color: "#584A5E"
}]

// /////////////////////////////////////////////////////////////////
// Radar Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartRadarData = {
      labels: ["Eating","Drinking","Sleeping","Designing","Coding","Partying","Running"],
    datasets: [{
               fillColor: "rgba(220,220,220,0.5)",
             strokeColor: "rgba(220,220,220,1)",
              pointColor: "rgba(220,220,220,1)",
        pointStrokeColor: "#fff",
                    data: [65,59,90,81,56,55,40]
    }, {
               fillColor: "rgba(151,187,205,0.5)",
             strokeColor: "rgba(151,187,205,1)",
              pointColor: "rgba(151,187,205,1)",
        pointStrokeColor: "#fff",
                    data: [28,48,40,19,96,27,100]
    }]
}

// /////////////////////////////////////////////////////////////////
// Pie Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartPieData = [{
    value: 30,
    color: "#F38630"
 }, {
    value: 50,
    color: "#E0E4CC"
 }, {
    value: 100,
    color: "#69D2E7"
}]

// /////////////////////////////////////////////////////////////////
// Doughnut Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartDoughnutData = [{
    value: 30,
    color: "#F7464A"
 }, {
    value: 50,
    color: "#E2EAE9"
 }, {
    value: 100,
    color: "#D4CCC5"
 }, {
    value: 40,
    color: "#949FB1"
 }, {
    value: 120,
    color: "#4D5360"
}]

// /////////////////////////////////////////////////////////////////
// Generate Doughnut Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartDoughnutDataGen = function () {
    return [{
        value: 130,
        color: "#F7464A"
     }, {
        value: 50,
        color: "#E2EAE9"
     }, {
        value: 100,
        color: "#D4CCC5"
     }, {
        value: 40,
        color: "#949FB1"
     }, {
        value: 120,
        color: "#4D5360"
    }];
}

// /////////////////////////////////////////////////////////////////
// Bar Chart Data Sample
// /////////////////////////////////////////////////////////////////

var ChartBarData = {
      labels: ["AngyBirds","Вконтакте","MS Word","Steam","Origin","Zanzara","TotalCommander"],
    datasets: [{
          fillColor: "rgba(220,220,220,0.5)",
        strokeColor: "rgba(220,220,220,1)",
               data: [65,59,90,81,56,55,40]
    }, {
          fillColor: "rgba(151,187,205,0.5)",
        strokeColor: "rgba(151,187,205,1)",
               data: [28,48,40,19,96,27,100]
    }]
}

function rand(max) {
    return Math.random() * (max - 0) + 0;
}

function rand100() {
    return rand(100);
}

function rand20() {
    return rand(20);
}

var BarGen = function() {
    return {
          labels: ["AngyBirds","Вконтакте","MS Word","Steam","Origin","Zanzara","TotalCommander"],
          datasets: [{
              fillColor: "rgba(220,220,220,0.5)",
            strokeColor: "rgba(220,220,220,1)",
                   data: [rand100(), rand100(), rand100(), rand100(), rand100(), rand100(), rand100()]
        }, {
              fillColor: "rgba(151,187,205,0.5)",
            strokeColor: "rgba(151,187,205,1)",
                   data: [rand100(),rand100(),rand100(),rand100(),rand100(),rand100(),rand100()]
        }]
    };
}

var LineGen = function() {
    return {
        labels: ["Понедельник","Вторник","Среда","Четверг","Пятница","СУббота","Воскресенье"],
      datasets: [{
                 fillColor: "rgba(220,120,120,0.5)",
               strokeColor: "rgba(220,120,120,1)",
                pointColor: "rgba(220,120,120,1)",
          pointStrokeColor: "#ffffff",
                      data: [rand20(), rand20(), rand20(), rand20(), rand20(), rand20(), rand20()]
      }, {
                 fillColor: "rgba(151,230,180,0.5)",
               strokeColor: "rgba(151,230,180,1)",
                pointColor: "rgba(151,230,180,1)",
          pointStrokeColor: "#ffffff",
                      data: [rand20(), rand20(), rand20(), rand20(), rand20(), rand20(), rand20()]
      }]
  };
}
